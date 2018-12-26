#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define INF 200000001
#define EPS 1e-9

typedef long long ll;
typedef complex<double> cd;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n, i,j,k,t;
int m, q;
int depth[1000010];
vector<int> adj[1000010];
int l;
int up[1000010][23];
int timer;
int tin[1000010], tout[1000010];

/* Copy From cp-algorithms.com */

void dfslca(int v, int p){
	tin[v] = ++timer;
    depth[v] = depth[p] + 1;
	up[v][0] = p;
	for(int i=1;i<=l;++i)
		up[v][i] = up[up[v][i-1]][i-1];
	for(int x : adj[v])
		if(x!=p)
			dfslca(x, v);
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

int main(){
    scanf("%d %d", &n, &m);
    getchar();
    for(i=-1;i<n;++i){
        char c, nxt;
        getchar();
        for(j=0;j<m;++j){
            c = getchar();
            nxt = getchar();
            if(i < 0) continue;
            int now = i*m + j;
            int right = now + 1;
            int down = now + m;
            if(c == ' '){
                adj[now].pb(down);
                adj[down].pb(now);
            }
            if(nxt == ' '){
                adj[now].pb(right);
                adj[right].pb(now);
            }
        }
        getchar();
    }
    n = n*m;
    preprocess(0);
    scanf("%d", &q);
    int a, b;
    scanf("%d %d", &a, &b);
    int now = --a*m + --b;
    ll sum = 0;
    for(i=1;i<q;++i){
        int nxt;
        scanf("%d %d", &a, &b);
        nxt = --a*m + --b;
        int anc = lca(now, nxt);
        sum += depth[now] + depth[nxt] - 2*depth[anc];
        now = nxt;
    }
    printf("%lld\n", sum);
	return 0;
}
