#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-9
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define debug2(a, b) cerr<<#a<<"="<<(a)<<" ";debug(b)
#define debug3(a, b, c) cerr<<#a<<"="<<(a)<<" ";debug2(b, c)
#define debug4(a, b, c, d) cerr<<#a<<"="<<(a)<<" ";debug3(b, c, d)
#define debug5(a, b, c, d, e) cerr<<#a<<"="<<(a)<<" ";debug4(b, c, d, e)
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<class T>
void printArray(const T * a, int n, ostream& out = cerr);
template<class T>
void printArray(const vector<T> &arr, ostream& out = cerr);

const ll mod = 1e9+7;
const double PI = acos(-1);

int n,i,j,k,t;
pair<pii, int> a[200002];
int tree[800010];
int lazy[800010];

void build(){
    memset(tree, 0, sizeof tree);
    memset(lazy, 0, sizeof lazy);
}

void propagate_lazy(int l, int r, int pos){
    tree[pos] += lazy[pos];
    if(l!=r){
        lazy[2*pos+1] += lazy[pos];
        lazy[2*pos+2] += lazy[pos];
    }
    lazy[pos] = 0;
}

int ql, qr, val;
void update(int l, int r, int pos){
    if(lazy[pos]){
        propagate_lazy(l, r, pos);
    }
    if(l > qr || r < ql) return;
    if(l>=ql && r<=qr){
        lazy[pos] += val;
        propagate_lazy(l, r, pos);
        return;
    }
    int mid = (l+r)/2;
    update(l, mid, 2*pos+1);
    update(mid+1, r, 2*pos+2);
    tree[pos] = max(tree[2*pos+1], tree[2*pos+2]);
}

int query(int l, int r, int pos){
    if(lazy[pos]){
        propagate_lazy(l, r, pos);
    }
   if(r < ql || l > qr)
       return 0;
   if(l>=ql && r<=qr)
       return tree[pos];
   int mid = (l+r)/2;
   return max(query(l, mid, 2*pos+1), query(mid+1, r, 2*pos+2));
}

int main(){
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;++i){
        scanf("%d %d", &a[i].fi.fi, &a[i].fi.se);
        a[i].se = i;
    }
    sort(a, a+n, [](const pair<pii, int> &a, const pair<pii, int> & b){
        if(a.fi.se == b.fi.se){
            return a.fi.fi < b.fi.fi;
        }
        return a.fi.se < b.fi.se;
    });
    build();
    vector<int> ans;
    val = 1;
    for(int i=0;i<n;++i){
        ql = a[i].fi.fi;
        qr = a[i].fi.se;
        if(query(1, 200000, 0) == k){
            ans.pb(a[i].se);
        }
        else {
            update(1, 200000, 0);
        }
    }
    printf("%d\n", (int)ans.size());
    for(int x : ans){
        printf("%d ", x+1);
    }
    puts("");
    return 0;
}

/* Template Function */
template<class T>
void printArray(const T * a, int n, ostream& out){
    for(int i=0;i<n;++i){
        out<<a[i]<<" ";
    }
    out<<endl;
}

template<class T>
void printArray(const vector<T> &arr, ostream& out){
    for(const T& x : arr){
        out<<x<<" ";
    }
    out<<endl;
}