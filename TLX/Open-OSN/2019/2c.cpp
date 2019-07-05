#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-9
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void printArray(const int *arr, int n);
void printArray(const vector<int> &arr);

const ll mod = 1e9+7;
const double PI = acos(-1);

template<class T>
struct mapper{
	std::vector<T> m;
	mapper(){}
	mapper(const T *arr, int sz){mapping(arr, sz);}
	mapper(const vector<T> &arr){mapping(arr);}
	void mapping(const T *arr, int sz){
		m.clear();
		for(int i=0;i<sz;++i)
			m.pb(arr[i]);
		sort(m.begin(), m.end());
		m.erase(unique(m.begin(), m.end()), m.end());
	}
	void mapping(const vector<T> &arr){
		m.clear();
		for(const T &x : arr)
			m.pb(x);
		sort(m.begin(), m.end());
		m.erase(unique(m.begin(), m.end()), m.end());
	}
	int get(const T &val){ return lower_bound(m.begin(), m.end(), val) - m.begin();}
	int operator[] (const T &val){ return get(val);}
};

int n,i,j,k,t;
int s, q;
int par[200005];
int cnt[200004];
int tree[1600020];
int lazy[1600020];
mapper<int> mep;
vector<int> v;

int find_par(int v){
    if(par[v] == v) return v;
    return par[v] = find_par(par[v]);
}

void build(){
    memset(tree, 1, sizeof tree);
    memset(lazy, 0, sizeof lazy);
}

void assignMin(int &a, int b){
    if(a > n || a<=0) a = b;
    else{
        int x = find_par(a);
        int y = find_par(b);
        // if(x != y) cerr<<"dapat "<<x<<" "<<y<<endl;
        if(x > y){
            par[x] = y;
        }
        else{
            par[y] = x;
        }
        a = min(x, y);
    }
}

int ql, qr, val;
void update(int l, int r, int pos){
    if(lazy[pos]) {
        // cerr<<pos<<" "<<lazy[pos]<<endl;
        assignMin(tree[pos], lazy[pos]);
        if(l!=r){
            assignMin(lazy[2*pos+1], lazy[pos]);
            assignMin(lazy[2*pos+2], lazy[pos]);
        }
        lazy[pos] = 0;
    }
    if(l > qr || r < ql) return;
    if(l>=ql && r<=qr){
        assignMin(tree[pos], val);
        if(l!=r){
            assignMin(lazy[2*pos+1], val);
            assignMin(lazy[2*pos+2], val);
            // cerr<<"> "<<l<<" "<<r<<" "<<lazy[2*pos+1]<<" "<<lazy[2*pos+2]<<endl;
        }
        return;
    }
    int mid = (l+r)/2;
    update(l, mid, 2*pos+1);
    update(mid+1, r, 2*pos+2);
    tree[pos] = min(tree[2*pos+1], tree[2*pos+2]);
}

int query(int l, int r, int pos){
    if(lazy[pos]) {
        // cerr<<pos<<" "<<lazy[pos]<<endl;
        assignMin(tree[pos], lazy[pos]);
        if(l!=r){
            assignMin(lazy[2*pos+1], lazy[pos]);
            assignMin(lazy[2*pos+2], lazy[pos]);
        }
        lazy[pos] = 0;
    }
    if(l > qr || r < ql) return 1e6;
    if(l>=ql && r<=qr){
        return tree[pos];
    }
    int mid = (l+r)/2;
    return min(
        query(l, mid, 2*pos+1),
        query(mid+1, r, 2*pos+2)
    );
}

void apply(int l, int r, int pos){
    if(lazy[pos]) {
        // cerr<<pos<<" "<<lazy[pos]<<endl;
        assignMin(tree[pos], lazy[pos]);
        if(l!=r){
            assignMin(lazy[2*pos+1], lazy[pos]);
            assignMin(lazy[2*pos+2], lazy[pos]);
        }
        lazy[pos] = 0;
    }
    if(l!=r){
        int mid = (l+r)/2;
        apply(l, mid, 2*pos+1);
        apply(mid+1, r, 2*pos+2);
        tree[pos] = min(tree[2*pos+1], tree[2*pos+2]);
    }
}

int main(){
    build();
	scanf("%d %d %d", &n, &s, &q);
    for(int i=1;i<=n;++i){
        par[i] = i;
    }
    vector<vector<pii>> a;
    for(int i=1;i<=n;++i){
        scanf("%d", &t);
        vector<pii> b;
        for(int j=0;j<t;++j){
            int c, d;
            scanf("%d %d", &c, &d);
            b.pb({c, d});
            v.pb(c);
            v.pb(d);
        }
        a.pb(b);
    }
    mep.mapping(v);
    for(int i=0;i<n;++i) {
        // cerr<<"MULAI "<<i<<endl;
        // cerr<<"par : "<<endl;
        // printArray(par+1, n);
        int mi = i+1;
        if(i){
            for(const pii & x : a[i]){
                ql = mep[x.fi];
                qr = mep[x.se];
                int res = query(0, mep.m.size(), 0);
                // cerr<<"> "<<mi<<" "<<res<<endl;
                if(res > n) continue;
                if(res <= 0){
                    // cerr<<i<<" "<<x.fi<<" "<<x.se<<" "<<res<<endl;
                    return -1;
                }
                mi = find_par(mi);
                res = find_par(res);
                // cerr<<">> "<<mi<<" "<<res<<endl;
                if(res > mi){
                    par[res] = mi;
                    mi = res;
                }
                else if(res < mi){
                    par[mi] = res;
                }
            }
        }
        // cerr<<"start update "<<i<<" "<<mi<<endl;
        for(const pii & x : a[i]){
            ql = mep[x.fi];
            qr = mep[x.se];
            // cerr<<"-update "<<x.fi<<" "<<x.se<<"<->"<<ql<<" "<<qr<<endl;
            val = mi;
            update(0, mep.m.size(), 0);
        }
    }
    apply(0, mep.m.size(), 0);
    memset(cnt, 0, sizeof cnt);
    for(int i=1;i<=n;++i){
        cnt[find_par(i)]++;
    }
    // printArray(par+1, n);
    while(q--){
        int x;
        scanf("%d", &x);
        printf("%d\n", cnt[find_par(x)]);
    }
	return 0;
}

/* Template Function */
void printArray(const int * a, int n){
	for(int i=0;i<n;++i){
		printf("%d ", a[i]);
	}
	puts("");
}

void printArray(const vector<int> &arr){
	for(int x : arr){
		printf("%d ", x);
	}
	puts("");
}