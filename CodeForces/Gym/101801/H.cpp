#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-9
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"

typedef long long ll;
typedef complex<double> cd;
typedef pair<int, int> pii;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
int a,b;
vector<int> adj[100002];
int sized[100002], parent[100002];

void dfs(int v, int p)
{
	parent[v] = p;
    sized[v] = 1;
    for (int u : adj[v]) {
        if (u != p){
            dfs(u, v);
			sized[v] += sized[u];
		}
    }
}

void preprocess(int root) {
	dfs(root, root);
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &n, &a, &b);
		a--; b--;
		for(i=1;i<n;++i){
			int x, y;
			scanf("%d %d", &x, &y);
			x--; y--;
			adj[x].pb(y);
			adj[y].pb(x);
		}
		preprocess(a);
		ll ans = 0;
		int presz = 0;
		int node = b;
		while(node != a){
			ans += 1LL*(n-sized[node])*(sized[node]-presz);
			presz = sized[node];
			node = parent[node];
		}
		printf("%lld\n", ans);
		for(i=0;i<n;++i)
			adj[i].clear();
	}
	return 0;
}