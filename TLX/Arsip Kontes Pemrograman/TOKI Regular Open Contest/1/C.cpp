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
int la, lb, q;
pii a[100002], b[100002];
map<ll, ll> ma, mb;

int main(){
	scanf("%d %d", &n, &q);
	la = lb = 0;
	for(i=0;i<q;++i){
		int x, y;
		scanf("%d %d %d", &t, &x, &y);
		if(t==1)
			ma[x] += y;
		else{
			ma[n] -= y;
			if(x < n)
				ma[n-x] += y;
		}
	}
	for(const pii &x : ma)
		a[la++] = x;
	sort(a, a+la);
	ll ans = 0;
	if(la){
		ans = max(ans, llabs(a[la-1].se));
		for(i=la-2;i>=0;--i){
			a[i].se += a[i+1].se;
			ans = max(ans, llabs(a[i].se));
		}
	}
	printf("%lld\n", ans);
	return 0;
}