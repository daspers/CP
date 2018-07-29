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
ll a[100002];

bool coba(ll t){
	bool col = false;
	ll lo = 0, la = 0;
	for(i=0;i<n;++i){
		if(a[i] < t){
			if(col){
				if(i - la > 1 || lo > t)
					return false;
			}
			lo = a[i]+1;
			la = i;
			col = true;
		}
		else if(a[i] > t)
			return false;
		t--;
	}
	if(la == n-1)
		return  t>=lo;
	return t==0;
}

int main(){
	scanf("%d", &n);
	ll st = 0;
	for(i=0;i<n;++i){
		scanf("%lld", a+i);
		st = max(st, a[i]+i);
	}
	ll l = st, r = 1e9+1e7;
	while(l < r){
		ll mid = (l+r)/2;
		if(coba(mid))
			r = mid;
		else
			l = mid+1;
	}
	ll ans = 0;
	for(ll i = st;i<=r;++i){
		if(coba(i)){
			ans = 0;
			ll tmp = i;
			for(j=0;j<n;++j){
				ans += tmp - a[j];
				tmp--;
			}
			ans += tmp*(tmp+1)/2;
			break;
		}
	}
	printf("%lld\n", ans);
	return 0;
}