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
std::vector<pii> adj[100002];
ll len[100002];
int nxt[100002], m;
int prv[100002];
bool vis[100002];

int main(){
	memset(len, -1, sizeof len);
	memset(nxt, -1, sizeof nxt);
	memset(prv, -1, sizeof prv);
	memset(vis, 0, sizeof vis);
	scanf("%d %d", &n, &m);
	for(i=0;i<m;++i){
		int x, y, w;
		scanf("%d %d %d", &x, &y, &w);
		adj[x].pb({y, w});
		adj[y].pb({x, w});
	}
	priority_queue<pair<ll, int>> pq;
	pq.push({0 ,1});
	len[1] = 0;
	while(!pq.empty()){
		pair<ll, int> tmp = pq.top();
		pq.pop();
		for(const pii &x : adj[tmp.se]){
			if(len[x.fi] == -1){
				len[x.fi] = x.se - tmp.fi;
				nxt[x.fi] = tmp.se;
				pq.push({-len[x.fi], x.fi});
			}
			else if(len[x.fi] > x.se - tmp.fi){
				len[x.fi] = x.se - tmp.fi;
				nxt[x.fi] = tmp.se;
				pq.push({-len[x.fi], x.fi});
			}
		}
	}
	if(len[0] == -1){
		puts("impossible");
		return 0;
	}
	queue<int> q;
	q.push(0);
	vis[0] = true;
	while(!q.empty()){
		int tmp = q.front();
		q.pop();
		if(tmp == 1)
			break;
		for(const pii &x : adj[tmp]){
			if(vis[x.fi] || nxt[tmp] == x.fi)
				continue;
			vis[x.fi] = true;
			prv[x.fi] = tmp;
			q.push(x.fi);
		}
	}
	std::vector<int> ans;
	for(i=1;i!=0;i = prv[i]){
		ans.pb(i);
		// cout<<i<<" "<<prv[i]<<endl;
		if(prv[i] == -1){
			puts("impossible");
			return 0;
		}
	}
	ans.pb(0);
	reverse(ans.begin(), ans.end());
	printf("%d", (int) ans.size());
	for(int x : ans)
		printf(" %d", x);
	puts("");
	return 0;
}
