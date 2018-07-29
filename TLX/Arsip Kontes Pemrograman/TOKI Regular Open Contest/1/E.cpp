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
vector<int> adj[100002];
ll peak[100002], ans[100002];

int main(){
	scanf("%d", &n);
	for(i=1;i<n;++i){
		int x, y;
		scanf("%d %d", &x, &y);
		adj[x].pb(y);
		adj[y].pb(x);
	}
	for(i=1;i<=n;++i){
		if(adj[i].size()<3){
			peak[i] = 0;
			continue;
		}
		peak[i] = 1LL*(adj[i].size()-1)*(adj[i].size()-2)/2;
		peak[i] %= mod;
	}
	for(i=1;i<=n;++i){
		if(adj[i].size() < 4){
			ans[i] = 0;
			continue;
		}
		ll sum = 0;
		ll sq = 0;
		for(int x : adj[i]){
			sum += peak[x];
			sq += peak[x]*peak[x]%mod;
		}
		sq %= mod;
		sum %= mod;
		sum = sum*sum%mod;
		sum = (sum - sq)%mod;
		sum = sum * 500000004LL % mod;
		if(sum < 0)
			sum += mod;
		ll tmp = 1LL*(adj[i].size()-2) * (adj[i].size()-3) / 2 % mod;
		ans[i] = sum * tmp % mod;
	}
	ll answer = 0;
	for(i=1;i<=n;++i){
		answer += ans[i];
		answer %= mod;
	}
	printf("%lld\n", answer);
	return 0;
}