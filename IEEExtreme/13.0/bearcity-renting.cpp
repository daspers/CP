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
pair<int, pii> a[200002];
vector<pii> adj[100002];
map<int, int> s[100002];
bool used[200002];
int m;
int par[100002];
int sz[100002];
int cnt[10002];
int up[100002][18];
int timer, l;
int tin[100002], tout[100002], dep[100002];

int find_set(int v){
    if(par[v] == v) return v;
    return par[v] = find_set(par[v]);
}

inline bool union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        par[b] = a;
        return true;
    }
    return false;
}

inline int maxi(int a, int b){
    return dep[a] < dep[b] ? a : b;
}

int dfs(int v, int p){
    int tot = 0;
    for(const pii & x : adj[v]){
        if(x.fi == p) continue;
        tot += dfs(x.fi, v);
        tot += !s[x.fi].count(x.se);
        for(const pii & y : s[x.fi]){
            if(y.se == v) continue;
            if(s[v].count(y.fi)) s[v][y.fi] = maxi(s[v][y.fi], y.se);
            else s[v][y.fi] = y.se;
        }
        // s[v].insert(s[x.fi].begin(), s[x.fi].end());
        s[x.fi].clear();
    }
    return tot;
}

void dfslca(int v, int p){
	tin[v] = ++timer;
    dep[v] = dep[p] + 1;
	up[v][0] = p;
	for(int i=1;i<=l;++i)
		up[v][i] = up[up[v][i-1]][i-1];
	for(const pii & x : adj[v])
		if(x.fi!=p)
			dfslca(x.fi, v);
	tout[v] = ++timer;
}

inline bool is_ancestor(int u, int v){
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v){
	if(is_ancestor(u, v))
		return u;
	if(is_ancestor(v, u))
		return v;
	for(int i=l;i>=0;--i)
		if(!is_ancestor(up[u][i], v))
			u = up[u][i];
	return up[u][0];
}

inline void preprocess(int root){
	memset(up, 0, sizeof up);
	timer = 0;
	l = ceil(log2(n));
	dfslca(root, root);
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i=0;i<m;++i){
        scanf("%d %d %d", &a[i].se.fi, &a[i].se.se, &a[i].fi);
    }
    for(int i=1;i<=n;++i){
        par[i] = i;
        sz[i] = 1;
    }
    sort(a, a+m);
    for(int i=0;i<m;++i){
        if(union_set(a[i].se.fi, a[i].se.se)){
            used[i] = true;
            adj[a[i].se.fi].pb({a[i].se.se, a[i]. fi});
            adj[a[i].se.se].pb({a[i].se.fi, a[i]. fi});
            cnt[a[i].fi]++;
        }
    }
    preprocess(1);
    for(int i=0;i<m;++i){
        if(used[i]) continue;
        if(cnt[a[i].fi]) {
            int anc = lca(a[i].se.fi, a[i].se.se);
            if(anc != a[i].se.fi){
                if(s[a[i].se.fi].count(a[i].fi)){
                    s[a[i].se.fi][a[i].fi] = maxi(s[a[i].se.fi][a[i].fi], anc);
                }
                else s[a[i].se.fi][a[i].fi] = anc;
            }
            if(anc != a[i].se.se){
                if(s[a[i].se.se].count(a[i].fi)){
                    s[a[i].se.se][a[i].fi] = maxi(s[a[i].se.se][a[i].fi], anc);
                }
                else s[a[i].se.se][a[i].fi] = anc;
            }
        }
    }
    // for(int x : w) cerr<<x<<" ";
    // cerr<<endl;
    int sum = dfs(1, 1);
    // debug(sum);
    printf("%d\n", sum);
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