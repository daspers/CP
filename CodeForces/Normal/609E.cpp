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
int m, q;
vector<pii> adj[200002];
int l;
int up[200002][32];
int timer;
int tin[200002], tout[200002];
int p[200002], depth[200002];
pair<int, pii> ed[200002];
pair<pii, pii> ced[200002];
bool used[200002];
int par[200002], ma[200002][32];

void dfslca(int v, int p){
	tin[v] = ++timer;
	up[v][0] = p;
	depth[v] = 1+depth[p];
	for(int i=1;i<=l;++i){
		up[v][i] = up[up[v][i-1]][i-1];
		ma[v][i] = max(ma[v][i-1], ma[up[v][i-1]][i-1]);
	}
	for(const pii &x : adj[v])
		if(x.fi!=p){
			ma[x.fi][0] = x.se;
			dfslca(x.fi, v);
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
	memset(ma, 0, sizeof ma);
	timer = 0;
	l = ceil(log2(n));
	depth[0] = 0;
	dfslca(root, root);
}

int find_set(int v){
	if(par[v] == v)
		return v;
	return par[v] = find_set(par[v]);
}

void union_set(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(a != b)
		par[b] = a;
}

int getmax(int nd, int len){
	int res = 0;
	for(int i=0;len;++i){
		if(len&1){
			res = max(res, ma[nd][i]);
			nd = up[nd][i];
		}
		len >>= 1;
	}
	return res;
}

int main(){
	scanf("%d %d", &n, &m);
	for(i=0;i<m;++i){
		int x, y, w;
		scanf("%d %d %d", &x, &y, &w);
		ed[i] = {w, {x, y}};
		ced[i] = {{w, i}, {x, y}};
		
	}
	for(i=1;i<=n;++i)
		par[i] = i;
	sort(ced, ced+m, [](const pair<pii, pii> &a, const pair<pii, pii> &b){
		return a.fi < b.fi;
	});
	memset(used, false, sizeof used);
	ll sum = 0;
	for(i=0;i<m;++i){
		int a = ced[i].se.fi;
		int b = ced[i].se.se;
		if(find_set(a) != find_set(b)){
			sum += ced[i].fi.fi;
			union_set(a, b);
			adj[a].pb({b, ced[i].fi.fi});
			adj[b].pb({a, ced[i].fi.fi});
			used[ced[i].fi.se] = true;
		}
	}
	preprocess(1);
	for(i=0;i<m;++i){
		if(used[i])
			printf("%lld\n", sum);
		else{
			int x = ed[i].se.fi;
			int y = ed[i].se.se;
			int anc = lca(x, y);
			int maxi = 0;
			if(anc != x)
				maxi = max(maxi, getmax(x, depth[x]-depth[anc]));
			if(anc != y)
				maxi = max(maxi, getmax(y, depth[y]-depth[anc]));
			printf("%lld\n", sum - maxi + ed[i].fi);
		}
	}
	return 0;
}