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
vector<int> adj[100002];
int depth[100002], par[100002], sum[100002];
int l;
int up[100002][32];
int timer;
int tin[100002], tout[100002];

void dfslca(int v, int p){
	tin[v] = ++timer;
	up[v][0] = p;
	depth[v] = depth[p]+1;
	par[v] = p;
	sum[v] = 1;
	for(int i=1;i<=l;++i)
		up[v][i] = up[up[v][i-1]][i-1];
	for(int x : adj[v])
		if(x!=p){
			dfslca(x, v);
			sum[v] += sum[x];
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
	depth[root] = 0;
	dfslca(root, root);
}

int getanc(int v, int sk){
	for(int i=0;sk;++i){
		if(sk&1)
			v = up[v][i];
		sk >>= 1;
	}
	return v;
}

int main(){
	scanf("%d", &n);
	for(i=1;i<n;++i){
		int x, y;
		scanf("%d %d", &x, &y);
		adj[x].pb(y);
		adj[y].pb(x);
	}
	preprocess(1);
	scanf("%d", &m);
	for(i=0;i<m;++i){
		int x, y;
		scanf("%d %d", &x, &y);
		int anc = lca(x, y);
		int len = depth[x] + depth[y] - 2*depth[anc];
		if(len == 0)
			printf("%d\n", sum[1]);
		else if(len&1)
			puts("0");
		else{
			if(depth[y] > depth[x])
				swap(x, y);
			len /= 2;
			int now = getanc(x, len);
			int ans= 0;
			if(now == anc)
				ans = sum[1] - sum[getanc(x, len-1)] - sum[getanc(y, len-1)];
			else
				ans = sum[now] - sum[getanc(x, len-1)];
			printf("%d\n", ans);
		}
	}
	return 0;
}