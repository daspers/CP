#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define INF 200000001
#define EPS 1e-9

typedef long long ll;
typedef complex<double> cd;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;

int main(){
	ll n;
	scanf("%lld", &n);
	if(n < 3){
		puts("-1");
		return 0;
	}
	// a = m^2 - n^2
	for(i=1;i<=sqrt(n);++i){
		if(n%i==0){
			ll tmp = n/i;
			if(tmp%2 == i%2){
				ll x = (tmp+i)/2; // m
				ll y = (tmp-i)/2; // n
				ll a = n;
				ll b = 2*x*y;
				ll c = x*x + y*y;
				if(a+b > c){
					printf("%lld %lld\n", b, c);
					return 0;
				}
			}
		}
	}
	// b = 2*m*n
	if(n % 2 == 0){
		for(i=1;i<=sqrt(n);++i){
			if(n%(2LL*i) == 0){
				ll x = n/2/i;
				ll y = i;
				ll a = x*x - y*y;
				ll b = n;
				ll c = x*x + y*y;
				if(a+b > c){
					printf("%lld %lld\n", a, c);
					return 0;
				}
			}
		}
	}
	puts("-1");
	return 0;
}
