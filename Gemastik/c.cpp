#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
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
ll ans[100002];

int main(){
	ans[1] = ans[0] = 1;
	for(i=2;i<=100000;++i){
		ans[i] = ((1LL*i*i)%mod * ans[i-1]) % mod;
		ans[i] -= (((1LL*i*(i-1)/2)%mod * (i-1))%mod * ans[i-2])%mod;
		ans[i] = (ans[i] + mod) % mod;
	}
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%lld\n", ans[n]);
	}
	return 0;
}