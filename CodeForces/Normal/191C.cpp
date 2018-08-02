#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-8
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
int m;
vector<pii> adj[100002];
pii e[100002];
int ans[100002];
int l;
int up[100002][32];
int timer;
int tin[100002], tout[100002];
int edge[100002], par[100002], sum[100002];

void dfslca(int v, int p){
	tin[v] = ++timer;
	up[v][0] = p;
	par[v] = p;
	for(int i=1;i<=l;++i)
		up[v][i] = up[up[v][i-1]][i-1];
	for(const pii &x : adj[v])
		if(x.fi!=p){
			dfslca(x.fi, v);
			edge[x.fi] = x.se;
		}
	tout[v] = ++timer;
}

bool is_ancestor(int u, int v){
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

void preprocess(int root){
	memset(up, 0, sizeof up);
	timer = 0;
	l = ceil(log2(n));
	dfslca(root, root);
}

int dfs(int v){
	for(const pii &x : adj[v])
		if(x.fi!=par[v]){
			sum[v] += dfs(x.fi);
		}
	if(v > 1)
		ans[edge[v]] = sum[v];
	return sum[v];
}

int main(){
	memset(sum, 0, sizeof sum);
	scanf("%d", &n);
	for(i=1;i<n;++i){
		int x, y;
		scanf("%d %d", &x, &y);
		adj[x].pb({y, i});
		adj[y].pb({x, i});
		e[i] = {x, y};
	}
	preprocess(1);
	scanf("%d", &m);
	for(i=0;i<m;++i){
		int x, y;
		scanf("%d %d", &x, &y);
		int anc = lca(x, y);
		if(y != anc){
			sum[anc]--;
			sum[y]++;
		}
		if(x != anc){
			sum[anc]--;
			sum[x]++;
		}
	}
	dfs(1);
	for(i=1;i<n;++i)
		printf("%d ", ans[i]);
	puts("");
	return 0;
}