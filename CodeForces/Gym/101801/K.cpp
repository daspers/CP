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
int m;
int mini[1000005];
vector<pii> adj[10005];
ll dp[10002][102];
bool vis[10005];

int calculate(int val){
	if(mini[val] == -1){
		vector<int> candidate;
		int sq = sqrt(val), tmp = val;
		for(int i=2;tmp>1&&i<=sq;++i){
			if(tmp%i==0){
				candidate.pb(i);
				do{
					tmp /= i;
				}while(tmp%i==0);
			}
		}
		if(tmp > 1)
			candidate.pb(tmp);
		mini[val] = 2*val+1;
		for(int x : candidate){
			mini[val] = min(mini[val], 2*x + val/x);
		}
	}
	return mini[val];
}

class comp{
	public:
	bool operator()(const pair<ll, pii> &a, const pair<ll, pii> &b){
		return a.fi>b.fi;
	}
};

int main(){
	memset(mini, -1, sizeof mini);
	mini[1] = 1;
	scanf("%d", &t);
	while(t--){
		memset(dp, -1, sizeof dp);
		scanf("%d %d %d", &n, &m, &k);
		for(i=0;i<m;++i){
			int x, y, w;
			scanf("%d %d %d", &x, &y, &w);
			--x; --y;
			adj[x].pb({y, w});
			adj[y].pb({x, w});
		}
		int a, b;
		scanf("%d %d", &a, &b); 
		--a; --b;
		dp[a][k] = 0;
		priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, comp> pq;
		pq.push({0, {a, k}});
		while(!pq.empty()){
			pair<ll, pii> tmp = pq.top();
			pq.pop();
			for(pii &x : adj[tmp.se.fi]){
				if(x.se > 1 && tmp.se.se && calculate(x.se) < x.se){
					if(dp[x.fi][tmp.se.se-1]==-1){
						dp[x.fi][tmp.se.se-1] = dp[tmp.se.fi][tmp.se.se] + calculate(x.se);
						pq.push({dp[x.fi][tmp.se.se-1], {x.fi, tmp.se.se-1}});
					}
					else if(dp[x.fi][tmp.se.se-1] > dp[tmp.se.fi][tmp.se.se] + calculate(x.se)){
						dp[x.fi][tmp.se.se-1] = dp[tmp.se.fi][tmp.se.se] + calculate(x.se);
						pq.push({dp[x.fi][tmp.se.se-1], {x.fi, tmp.se.se-1}});
					}
				}
				if(dp[x.fi][tmp.se.se]==-1){
					dp[x.fi][tmp.se.se] = dp[tmp.se.fi][tmp.se.se] + x.se;
					pq.push({dp[x.fi][tmp.se.se], {x.fi, tmp.se.se}});
				}
				else if(dp[x.fi][tmp.se.se] > dp[tmp.se.fi][tmp.se.se] + x.se){
					dp[x.fi][tmp.se.se] = dp[tmp.se.fi][tmp.se.se] + x.se;
					pq.push({dp[x.fi][tmp.se.se], {x.fi, tmp.se.se}});
				}
			}
		}
		ll ans = -1;
		for(i=0;i<=k;++i){
			if(dp[b][i]==-1)
				continue;
			if(ans==-1)
				ans = dp[b][i];
			ans = min(ans, dp[b][i]);
		}
		printf("%lld\n", ans);
		for(i=0;i<=n;++i)
			adj[i].clear();
	}
	return 0;
}