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
int m, ma;
int a[1003], p[1003], c[1003], dim;
vector<int> adj[1003], v;
vector<pii> w;
bool vis[1003];

void dfs(int v, int p, int dep){
    vis[v] = true;
    ma = max(ma, dep);
    for(int x : adj[v]){
        if(x == p) continue;
        dfs(x, v, dep+1);
    }
}

int find_set(int v){
    if(v == p [v])
        return v;
    return p[v] = find_set(p[v]);
}

void union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        p[b] = a;
    }
}

int main(){
    memset(vis, 0, sizeof vis);
	scanf("%d %d", &n, &m);
    for(i=1;i<=n;++i){
        p[i] = i;
        a[i] = n;
    }
    for(i=0;i<m;++i){
        int x, y;
        scanf("%d %d", &x, &y);
        adj[x].pb(y);
        adj[y].pb(x);
        union_set(x, y);
    }
    for(i=1;i<=n;++i){
        ma = 0;
        dfs(i,i,0);
        int par = find_set(i);
        if(a[par] > ma){
            a[par] = ma;
            c[par] = i;
        }
        dim = max(dim, ma);
    }
    for(i=1;i<=n;++i)
        v.pb(find_set(i));
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    sort(v.begin(), v.end(), [](int x, int y) -> bool {
        return a[x] > a[y];
    });
    for(i=1;i<v.size();++i){
        w.pb({c[v[0]], c[v[i]]});
        adj[c[v[0]]].pb(c[v[i]]);
        adj[c[v[i]]].pb(c[v[0]]);
    }
    dim = 0;
    for(i=1;i<=n;++i){
        ma = 0;
        dfs(i,i,0);
        dim = max(ma, dim);
    }
    printf("%d\n", dim);
    for(const pii &x : w){
        printf("%d %d\n", x.fi, x.se);
    }
	return 0;
}