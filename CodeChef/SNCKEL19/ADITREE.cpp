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

struct edge{
	int first, second, id;
	edge(){}
	edge(int fi, int se, int id):first(fi), second(se), id(id){}
};

int n,i,j,k,t;
int q, sum;
// vector<int> adj[250002];
const int maxn = 250050;
vector<edge> G[maxn];
int son[maxn], siz[maxn], dep[maxn], top[maxn];
int tid[maxn], rid[maxn], fa[maxn], dfs_clock;
int tree[4*maxn], cost[maxn], eid[maxn];
int lazy[4*maxn];

void dfs0(int u, int f, int d, int w, int id){
	fa[u] = f;
	son[u] = -1;
	siz[u] = 1;
	dep[u] = d;
	cost[u] = w;
	eid[id] = u;
	for(int i=0;i<G[u].size();++i){
		int t = G[u][i].first;
		if(t!=f){
			dfs0(t,u,d+1,G[u][i].second,G[u][i].id);
			siz[u] += siz[t];
			if(son[u] == -1 || siz[t] > siz[son[u]])
				son[u] = t;
		}
	}
}

void dfs1(int u, int fa, int tp){
	top[u] = tp;
	tid[u] = ++dfs_clock;
	rid[dfs_clock] = u;
	if(son[u] == -1) return;
	dfs1(son[u], u, tp);
	for(int i=0;i<G[u].size();++i){
		int t = G[u][i].first;
		if(t!=fa && t!=son[u]){
			dfs1(t, u, t);
		}
	}
}

void build(){
	memset(lazy, 0, sizeof lazy);
	memset(tree, 0, sizeof tree);
}

int query(int u, int l, int r, int ql ,int qr){
	if(lazy[u]){
		tree[u] = r-l+1 - tree[u];
		if(l!=r){
			lazy[u<<1] ^= 1;
			lazy[u<<1|1] ^= 1;
		}
		lazy[u] = 0;
	}
	if(l > qr || r < ql) return 0;
	if(ql<=l && r<=qr) return tree[u];
	int mid = (l+r)>>1, res = 0;
	res += query(u<<1, l, mid, ql, qr);
	res += query(u<<1|1, mid+1, r, ql, qr);
	tree[u] = tree[u<<1] + tree[u<<1|1];
	return res;
}

void update(int u, int l ,int r, int ql, int qr){
	if(lazy[u]){
		tree[u] = r-l+1 - tree[u];
		if(l!=r){
			lazy[u<<1] ^= 1;
			lazy[u<<1|1] ^= 1;
		}
		lazy[u] = 0;
	}
	if(l > qr || r < ql)
		return;
	if(ql<=l && r<=qr){
		tree[u] = r-l+1 - tree[u];
		if(l!=r){
			lazy[u<<1] ^= 1;
			lazy[u<<1|1] ^= 1;
		}
		return;
	}
	int mid = (l+r)>>1;
	update(u<<1, l, mid, ql, qr);
	update(u<<1|1, mid+1, r, ql, qr);
	tree[u] = tree[u<<1] + tree[u<<1|1];
}

void printtree(int u, int l ,int r){
	if(lazy[u]){
		tree[u] = r-l+1 - tree[u];
		if(l!=r){
			lazy[u<<1] ^= 1;
			lazy[u<<1|1] ^= 1;
		}
		lazy[u] = 0;
	}
	if(l == r){
		cout<<l<<": "<<tree[u]<<endl;
		return;
	}
	int mid = (l+r)>>1;
	printtree(u<<1, l, mid);
	printtree(u<<1|1, mid+1, r);
	tree[u] = tree[u<<1] + tree[u<<1|1];
}


int linkquery(int u, int v){
	int res = 0;
	while(top[u] != top[v]){
		if(dep[top[u]] < dep[top[v]]) swap(u, v);
		res += query(1,1,n,tid[top[u]],tid[u]);
		u = fa[top[u]];
	}
	if(dep[u] < dep[v]) swap(u, v);
	if(u == v) return res;
	return res + query(1, 1, n, tid[son[v]], tid[u]);
}

void linkupdate(int u, int v){
	while(top[u] != top[v]){
		if(dep[top[u]] < dep[top[v]]) swap(u, v);
		update(1,1,n,tid[top[u]],tid[u]);
		u = fa[top[u]];
	}
	if(dep[u] < dep[v]) swap(u, v);
	if(u == v) return;
	update(1, 1, n, tid[son[v]], tid[u]);
}

int main(){
	scanf("%d", &n);
	for(i=1;i<n;++i){
		int a, b;
		scanf("%d %d", &a, &b);
		G[a].pb(edge(b,0,i));
		G[b].pb(edge(a,0,i));
	}
	if(n == 1){
		scanf("%d", &q);
		while(q--){
			int a, b;
			scanf("%d %d", &a, &b);
			puts("0");
		}
		return 0;
	}
	dfs0(1,1,1,0,0);
	dfs1(1,1,1);
	build();
	// sum = 0;
	scanf("%d", &q);
	while(q--){
		int a, b;
		scanf("%d %d", &a, &b);
		// sum -= linkquery(a, b);
		linkupdate(a, b);
		// printtree(1, 1, n);
		// sum += linkquery(a, b);
		printf("%d\n", tree[1]);
	}
    return 0;
}