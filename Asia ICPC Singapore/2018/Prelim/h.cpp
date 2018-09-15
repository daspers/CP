#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-8
#define EPS 1e-8
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
vector<vector<int>> v;
vector<int> adj[125001];
char vis[125001];
int a[125001];
vector<int> fc;
set<int> edges;
set<pii> udah;
int ans = 0;

int dfs(int v){
	for(int x : adj[v]){
		if(vis[x] == 1)
			continue;
		if(vis[x] == 2){
			if(!udah.count({v, x})){
				// cout<<v<<" "<<x<<endl;
				ans++;
				udah.insert({v, x});
			}
			continue;
		}
		vis[x] = 1;
		dfs(x);
	}
}

int main(){
	memset(vis, 0, sizeof vis);
	scanf("%d %d", &n, &k);
	if(n==1)
		return puts("6") & 0;
	int now = 1;
	vector<int> wew;
	for(i=0;i<n-1;++i){
		wew.clear();
		for(j=0;j<i+n;++j){
			wew.pb(now++);
		}
		v.pb(wew);
	}
	wew.clear();
	for(i=0;i<2*n-1;++i)
		wew.pb(now++);
	v.pb(wew);
	for(i=n-2;i>=0;--i){
		wew.clear();
		for(j=0;j<i+n;++j){
			wew.pb(now++);
		}
		v.pb(wew);
	}
	for(const vector<int> &x : v){
		for(i=1;i<x.size();++i){
			adj[x[i]].pb(x[i-1]);
			adj[x[i-1]].pb(x[i]);
		}
	}
	// cout<<"shit"<<endl;
	for(i=0;i<n-1;++i){
		for(j=0;j<v[i].size();++j){
			adj[v[i][j]].pb(v[i+1][j]);
			adj[v[i+1][j]].pb(v[i][j]);
			adj[v[i][j]].pb(v[i+1][j+1]);
			adj[v[i+1][j+1]].pb(v[i][j]);
		}
	}
	int len = v.size();
	for(i=n-1;i>0;--i){
		for(j=0;j<v[len-i].size();++j){
			adj[v[len-i][j]].pb(v[len-i-1][j]);
			adj[v[len-i-1][j]].pb(v[len-i][j]);
			adj[v[len-i][j]].pb(v[len-i-1][j+1]);
			adj[v[len-i-1][j+1]].pb(v[len-i][j]);
		}
	}
	for(i=0;i<n;++i)
		fc.pb(v[0][i]);
	for(i=0;i<n;++i)
		fc.pb(v[len-1][i]);
	for(i=1;i<v.size()-1;++i){
		fc.pb(v[i].front());
		fc.pb(v[i].back());
	}
	edges.insert(v[0].front());
	edges.insert(v[0].back());
	edges.insert(v[len-1].front());
	edges.insert(v[len-1].back());
	edges.insert(v[len/2].front());
	edges.insert(v[len/2].back());
	for(i=0;i<k;++i){
		scanf("%d", a+i);
		vis[a[i]] = 2;
	}
	for(int x : fc){
		if(vis[x] != 0){
			if(vis[x] == 2){
				ans +=  edges.count(x) + 2;
			}
			continue;
		}
		dfs(x);
	}
	// cout<<udah.size()<<endl;
	printf("%d\n", ans);
	return 0;
}