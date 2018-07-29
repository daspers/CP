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
typedef pair<ll, ll> pii;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
int m;
vector<int> adj[105];
bool vis[104];
int depth[104];

int main(){
	scanf("%d", &t);
	while(t--){
		int st;
		scanf("%d %d %d", &n, &m, &st);
		for(i=0;i<m;++i){
			int x, y;
			scanf("%d %d", &x, &y);
			adj[x].pb(y);
			adj[y].pb(x);
		}
		memset(depth, -1, sizeof depth);
		queue<int> q;
		q.push(st);
		depth[st] = 1;
		while(!q.empty()){
			int tmp = q.front();
			q.pop();
			for(int x : adj[tmp]){
				if(depth[x] != -1)
					continue;
				depth[x] = 1+depth[tmp];
				q.push(x);
			}
		}
		printf("%d\n", *max_element(depth+1, depth+1+n));
		for(i=1;i<=n;++i)
			adj[i].clear();
	}
	return 0;
}