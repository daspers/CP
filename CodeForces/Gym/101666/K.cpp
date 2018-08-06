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
string s[1002];
std::vector<int> adj[1002], ans;
bool vis[1002];

void dfs(int v){
	for(int x : adj[v]){
		if(vis[x])
			continue;
		vis[x] = true;
		dfs(x);
	}
	ans.pb(v);
}

int main(){
	scanf("%d", &n);
	for(i=0;i<n;++i)
		cin>>s[i];
	for(i=0;i<n;++i)
		for(j=0;j<n;++j){
			if(s[i][j]=='1')
				adj[i].pb(j);
		}
	vis[0] = true;
	dfs(0);
	if(ans.size() != n){
		puts("impossible");
		return 0;
	}
	for(int x : ans)
		printf("%d ", x);
	puts("");
	return 0;
}
