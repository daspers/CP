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

const ll mod = 1e9+7;
const double PI = acos(-1);

int n,i,j,k,t;
int a[300002];
vector<pii> adj[300002];
ll res;
ll ans = 0;

void dfs(int v, int p){
    ll now = a[v];
    ans = max(ans, now);
    priority_queue<ll> pq;
    for(const pii &x : adj[v]){
        if(x.fi == p) continue;
        dfs(x.fi, v);
        if(res > x.se){
            pq.push(res - x.se);
            res = res - x.se + a[v];
            now = max(now, res);
        }
    }
    if(pq.size() > 1){
        ll tmp = pq.top();
        pq.pop();
        tmp += pq.top();
        tmp += a[v];
        ans= max(ans, tmp);
    }
    ans = max(ans, now);
    swap(now, res);
}

int main(){
	scanf("%d", &n);
    for(i=1;i<=n;++i)
        scanf("%d", a+i);
    for(i=1;i<n;++i){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    res = 0;
    dfs(1,1);
    printf("%lld\n", ans);
	return 0;
}