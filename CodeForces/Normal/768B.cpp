#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1e9+7;
const double pi = acos(-1);

ll t, n, i, j, k;
ll l,r;
ll p[64];

inline ll log2(ll n){
	ll ans = 0;
	while(n>1){
		++ans;
		n >>=1;
	}
	return ans;
}

ll dnc(ll n, ll x){
	ll mid = (p[log2(n)])/2;
	if(mid == x)
		return n&1;
	else if(x < mid)
		return dnc(n/2, x);
	else
		return dnc(n/2, x - mid - 1);
}

int main(){
	p[0] = 1;
	for(i=1;i<=63;i++){
		p[i] = 1 + 2*p[i-1];
	}
	scanf("%lld %lld %lld", &n, &l, &r);
	ll ans = 0;
	while(l<=r){
		ans += dnc(n, l-1);
		l++;
	}
	printf("%lld\n", ans);
	return 0;
}