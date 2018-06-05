#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define Nmax 300000 
#define EPS 1e-9

typedef long long ll;
typedef complex<double> cd;

const ll mod = 1e9+7;
const double pi = acos(-1);

ll n, i,j,k,t;
ll p2[32];

ll pow2(ll x){
	ll res = 1;
	for(int i=0;x;++i){
		if(x&1)
			res = res * p2[i] % mod;
		x >>= 1;
	}
	return res;
}

ll inverse(ll val){
	if(val == 1)
		return 1;
	ll res = (mod-mod/val*inverse(mod%val))%mod;
	return res;
}

int main(){
	p2[0] = 2;
	for(int i=1;i<32;++i)
		p2[i] = p2[i-1]*p2[i-1]%mod;
	scanf("%lld", &t);
	for(int cc =1; cc<=t;++cc){
		printf("Case #%d: ", cc);
		scanf("%lld %lld", &n, &k);
		ll ans = pow2(n);
		ll minus = 1;
		ll inv = 1;
		for(int i=0;i<k;++i){
			ans = (ans - minus) % mod;
			minus *= n--;
			minus %= mod;
			minus *= inverse(inv++);
			minus %= mod;
			// cout<<ans<<" "<<minus<<endl;
		}
		if(ans < 0)
			ans += mod;
		printf("%lld\n", ans);
	}
	return 0;
}