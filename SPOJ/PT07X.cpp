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
const double PI = acos(-1);

int n,i,j,k,t;
vector<int> adj[100003];
int dp[100002][2];

int solve(int v, int p, int mode){
	if(dp[v][mode]==-1){
		if(adj[v].size()==1 && v!=p){
			dp[v][mode] = mode == 0;
		}
		else{
			dp[v][mode] = 1;
			for(int x : adj[v]){
				if(x!=p){
						dp[v][mode] += solve(x,v,1);
				}
			}
			if(mode){
				int tmp = 0;
				for(int x : adj[v]){
					if(x!=p){
						tmp += solve(x,v,0);
					}
				}
				dp[v][mode] = min(dp[v][mode], tmp);
			}
		}
	}
	return dp[v][mode];
}

int main(){
	memset(dp, -1, sizeof dp);
	scanf("%d", &n);
	for(i=1;i<n;++i){
		int x,y;
		scanf("%d %d", &x, &y);
		adj[x].pb(y);
		adj[y].pb(x);
	}
	for(i=1;i<=n;++i){
		if(adj[i].size()==1){
			printf("%d\n", min(solve(i,i,0), solve(i,i,1)));
			return 0;
		}
	}
	// for(i=1;i<=n;++i){
		// cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
	// }
	puts("0");
	return 0;
}