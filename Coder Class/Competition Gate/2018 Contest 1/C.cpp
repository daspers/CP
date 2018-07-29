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
// typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;

const ll mod = 1e9+7;
const double PI = acos(-1);

int n,i,j,k,t;
int m;
vector<pii> adj[100002];

void addadj(int node, int nxt, int cost){
	if(adj[node].size()<2){
		adj[node].pb({nxt, cost});
		if(adj[node].size()==2){
			if(adj[node][0].se > adj[node][1].se || (adj[node][0].se == adj[node][1].se && adj[node][0].fi > adj[node][1].fi))
				swap(adj[node][0], adj[node][1]);
		}
	}
	else{
		if(cost > adj[node][1].se || (cost == adj[node][1].se && nxt > adj[node][1].fi))
			return;
		adj[node][1] = {nxt, cost};
		if(adj[node][0].se > adj[node][1].se || (adj[node][0].se == adj[node][1].se && adj[node][0].fi > adj[node][1].fi))
			swap(adj[node][0], adj[node][1]);
	}
}

int main(){
	scanf("%d %d %d %d", &n, &m, &k, &t);
	for(i=0;i<m;++i){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adj[a].pb({b, c});
		adj[b].pb({a, c});
	}
	for(i=0;i<n;++i){
		if(adj[i].size()>1){
			sort(adj[i].begin(), adj[i].end(), [](const pii &a, const pii &b){
				if(a.se==b.se)
					return a.fi < b.fi;
				return a.se < b.se;
			});
			if(adj[i].size()>2){
				adj[i].erase(adj[i].begin()+2, adj[i].end());
			}
		}
	}
	queue<pii> q;
	q.push({t, t});
	ll ans = 0;
	while(k>0 && !q.empty()){
		pii tmp = q.front();
		q.pop();
		for(pii x : adj[tmp.fi]){
			if(tmp.se != x.fi){
				ans += x.se;
				q.push({x.fi, tmp.fi});
				break;
			}
		}
		k--;
	}
	printf("%lld\n", ans);
	return 0;
}