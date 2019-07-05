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
int m,s;
pair<pii, int> p[2000005];
ll dp[200005];
ll tree[800020];
ll ptree[800020];

void build(int l, int r, int pos){
    if(l==r){
        ptree[pos] = tree[pos] = 1e18;
        return;
    }
    int mid=(l+r)/2;
    build(l, mid, 2*pos+1);
    build(mid+1, r, 2*pos+2);
    tree[pos] = min(tree[2*pos+1], tree[2*pos+2]);
    ptree[pos] = min(ptree[2*pos+1], ptree[2*pos+2]);
}

void update(int l, int r, int pos, int idx, ll val){
    if(r < idx || l > idx) return;
    if(l==r){
        tree[pos] = min(tree[pos], val);
        ptree[pos] = min(ptree[pos],val + 1LL*(n-l)*s);
        return;
    }
    int mid=(l+r)/2;
    update(l, mid, 2*pos+1, idx, val);
    update(mid+1, r, 2*pos+2, idx, val);
    tree[pos] = min(tree[2*pos+1], tree[2*pos+2]);
    ptree[pos] = min(ptree[2*pos+1], ptree[2*pos+2]);
}

ll query(int l, int r, int pos, int ql, int qr){
    if(r<ql || l>qr || l>r){
        return 1e18;
    }
    if(l>=ql && r<=qr){
        return tree[pos];
    };
    int mid = (l+r)/2;
    ll a = query(l, mid, 2*pos+1, ql, qr);
    ll b = query(mid+1, r, 2*pos+2, ql, qr);
    return min (a,b);
}

ll queryp(int l, int r, int pos, int ql, int qr){
    if(r<ql || l>qr || l>r) return 1e18;
    if(l>=ql && r<=qr){
        return ptree[pos];
    }
    int mid = (l+r)/2;
    return min (
        queryp(l, mid, 2*pos+1, ql, qr),
        queryp(mid+1, r, 2*pos+2, ql, qr)
    );
}

int main(){
    memset(dp, -1, sizeof dp);
	scanf("%d %d %d", &n, &m, &s);
    for(int i=0;i<m;++i){
        scanf("%d %d %d", &p[i].fi.fi, &p[i].fi.se, &p[i].se);
    }
    build(0, n, 0);
    update(0, n, 0, 0, 0);
    sort(p, p+m, [](const pair<pii, int> &a, const pair<pii, int> &b){
        if(a.fi.se == b.fi.se){
            return a.fi.fi < b.fi.fi;
        }
        return a.fi.se < b.fi.se;
    });
    dp[0] = 0;
    for(int i=1;i<=n;++i)
        dp[i] = 1e18;
    for(int i=0;i<m;++i){
        ll now = min(
            query(0, n, 0, p[i].fi.fi, p[i].fi.se-1),
            queryp(0, n, 0, 0, p[i].fi.fi-1) - 1LL*(n-p[i].fi.fi+1) * s
        ) + p[i].se;
        dp[p[i].fi.se] = min(dp[p[i].fi.se], now);
        update(0, n, 0, p[i].fi.se, dp[p[i].fi.se]);
    }
    dp[n] = min(dp[n], queryp(0, n, 0, 0, n-1));
    // debug(queryp(0, n, 0, 0, n-1));
    printf("%lld\n", dp[n]);
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