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

void printArray(const ll *arr, int n);
void printArray(const vector<int> &arr);

const ll mod = 1e9+7;
const double PI = acos(-1);

int n,i,j,k,t;
int m;
int c[100002];
vector<pii> adj[100002];
vector<int> tele[100002], tel[100002];
ll dist0[100002];
ll distn[100002];
bool vis[100002];

void fill_dist(ll *dist, int node) {
	memset(dist, -1, n * sizeof(ll));
	memset(vis, 0, sizeof vis);
	dist[node] = 0;
	priority_queue<pair<ll, int>> pq;
	pq.push({0, node});
	while(!pq.empty()){
		pair<ll, int> tmp = pq.top();
		pq.pop();
		
		if (vis[tmp.se]) continue;
		vis[tmp.se] = true;

		for(const pii & x : adj[tmp.se]) {
			if(dist[x.fi] == -1 || (dist[x.fi] != -1 && dist[x.fi] > -tmp.fi + x.se)) {
				dist[x.fi] = -tmp.fi + x.se;
				pq.push({-dist[x.fi], x.fi});
			}
		}

		for(int t : tel[tmp.se]) {
			for(int x : tele[t]){
				if(x == tmp.se) continue;
				if(dist[x] == -1 || (dist[x] != -1 && dist[x] > -tmp.fi + c[t])) {
					dist[x] = -tmp.fi + c[t];
					pq.push({-dist[x], x});
				}
			}
		}
	}
}

int main(){
	scanf("%d %d %d", &n, &m, &k);
	for(int i=0;i<m;++i){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		--a, --b;
		adj[a].pb({b, c});
		adj[b].pb({a, c});
	}
	for(int i=0;i<n;++i){
		scanf("%d", &t);
		for(int j=0;j<t;++j){
			int a;
			scanf("%d", &a);
			tele[--a].pb(i);
			tel[i].pb(a);
		}
	}
	for(int i=0;i<k;++i){
		scanf("%d", c+i);
	}
	fill_dist(dist0, 0);
	ll ans = dist0[n-1];
	printf("%lld\n", ans);
	return 0;
}

/* Template Function */
void printArray(const ll * a, int n){
	for(int i=0;i<n;++i){
		printf("%lld ", a[i]);
	}
	puts("");
}

void printArray(const vector<int> &arr){
	for(int x : arr){
		printf("%d ", x);
	}
	puts("");
}