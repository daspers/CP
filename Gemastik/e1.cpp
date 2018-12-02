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
int d, m;

int main(){
	scanf("%d %d %d %d", &n, &m, &t, &d);
	int divn = n/(t+d);
	int divm = m/(t+d);
	int remn = n%(t+d);
	int remm = m%(t+d);
	if(remn >= t){
		divn++;
		remn = 0;
	}
	if(remm >= t){
		divm++;
		remm = 0;
	}
	ll ans = 1LL*divn*divm*((1LL*t*t+1)/2);
	if(remn){
		ans += 1LL*divm*((remn*t+1)/2);
	}
	if(remm){
		ans += 1LL*divn*((remm*t+1)/2);
	}
	if(remn && remm){
		ans += 1LL*(remm*remn+1)/2;
	}
	printf("%lld\n", ans);
	return 0;
}