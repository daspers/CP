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

int n,i,j,k,t;
int m;
pii p[200003];
pii tree[1600020];
pii after[200003];
vector<int> mapper;

void build(){
    memset(tree, 0, sizeof tree);
}

void update(int l, int r, int pos, int idx, pii val){
    if(l > idx || r < idx) return;
    if(l == r){
        tree[pos] = max(tree[pos], val);
        return;
    }
    int mid = (l+r)/2;
    update(l, mid, 2*pos+1, idx, val);
    update(mid+1, r, 2*pos+2, idx, val);
    tree[pos] = max(tree[2*pos+1], tree[2*pos+2]);
}

pii query(int l, int r, int pos, int ql, int qr){
    if(r < ql || l > qr) return {0,0};
    if(l>=ql && r<=qr) return tree[pos];
    int mid = (l+r)/2;
    return max(
        query(l, mid, 2*pos+1, ql, qr),
        query(mid+1, r, 2*pos+2, ql, qr)
    );
}

int get(int val){
    return lower_bound(mapper.begin(), mapper.end(), val) - mapper.begin();
}

int getr(int val){
    return upper_bound(mapper.begin(), mapper.end(), val) - mapper.begin() - 1;
}

int main(){
	scanf("%d %d", &n, &m);
    for(int i=0;i<n;++i){
        scanf("%d %d", &p[i].fi, &p[i].se);
        mapper.pb(p[i].fi);
    }
    sort(mapper.begin(), mapper.end());
    mapper.erase(unique(mapper.begin(), mapper.end()), mapper.end());
    // build();
    for(int i=0;i<n;++i){
        // update(0, mapper.size(), 0, get(p[i].fi), {p[i].se+1, i});
        after[get(p[i].fi)] = max(after[get(p[i].fi)], {p[i].se+1, i});
    }
    for(int i=1;i<=mapper.size();++i){
        after[i] = max(after[i], after[i-1]);
    }
    sort(p, p+n);
    int lst = 1;
    for(int i=0;i<n;++i){
        if(p[i].fi > lst){
            return puts("NO"), 0;
        }
        lst = max(lst, p[i].se+1);
    }
    if(lst <= m){
        return puts("NO"), 0;
    }
    // cerr<<"udah update"<<endl;
    vector<int> ans;
    for(int i=1;i<=m;){
        // pii nxt = query(0, mapper.size(), 0, 0, get(i));
        pii nxt = after[getr(i)];
        ans.pb(nxt.se);
        // cerr<<"sekarang "<<i<<" cari "<<getr(i)<<" dapet "<<mapper[nxt.fi]<<endl;
        i = nxt.fi;
    }
    puts("YES");
    printf("%d\n", (int)ans.size());
    for(int x : ans){
        printf("%d ", x+1);
    }
    puts("");
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