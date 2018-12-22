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
vector<int> adj[100002];
int l;
int up[100002][32];
int timer;
int tin[100002], tout[100002];
vector<int> ss[100002][32];
int p[100002], depth[100002];

vector<int> merge(const vector<int> &a, const vector<int> &b, int ma){
	vector<int> res;
	int i, j;
	for(i=j=0;i<a.size() && j<b.size() && res.size() < ma;){
		if(a[i] < b[j])
			res.pb(a[i++]);
		else
			res.pb(b[j++]);
	}
	while(res.size() < ma && i < a.size())
		res.pb(a[i++]);
	while(res.size() < ma && j < b.size())
		res.pb(b[j++]);
	return res;
}

void dfslca(int v, int p){
	tin[v] = ++timer;
	up[v][0] = p;
	depth[v] = 1+depth[p];
	for(int i=1;i<=l;++i){
		up[v][i] = up[up[v][i-1]][i-1];
		ss[v][i] = merge(ss[v][i-1], ss[up[v][i-1]][i-1], 10);
	}
	for(int x : adj[v])
		if(x!=p){
			dfslca(x, v);
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
	depth[0] = 0;
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
	scanf("%d %d %d", &n, &m, &q);
	for(i=1;i<n;++i){
		int x, y;
		scanf("%d %d", &x, &y);
		adj[x].pb(y);
		adj[y].pb(x);
	}
	for(i=1;i<=m;++i){
		scanf("%d", p+i);
		ss[p[i]][0].pb(i);
	}
	for(i=1;i<=n;++i)
		if(ss[i][0].size()>1)
			sort(ss[i][0].begin(), ss[i][0].end());
	preprocess(1);
	for(i=0;i<q;++i){
		int x, y, a;
		scanf("%d %d %d", &x, &y, &a);
		int anc = lca(x,y);
		vector<int> ans;
		int len = depth[x] - depth[anc], now = x;
		for(j=0;len;++j){
			if(len&1){
				ans = merge(ans, ss[now][j], a);
				now = up[now][j];
			}
			len >>= 1;
		}
		len = depth[y] - depth[anc];
		now = y;
		for(j=0;len;++j){
			if(len&1){
				ans = merge(ans, ss[now][j], a);
				now = up[now][j];
			}
			len >>= 1;
		}
		ans = merge(ans, ss[anc][0], a);
		printf("%d", (int) ans.size());
		for(int w : ans)
			printf(" %d", w);
		puts("");
	}
	return 0;
}