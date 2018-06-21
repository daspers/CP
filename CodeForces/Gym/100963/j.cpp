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

ll extended_euclidean(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = extended_euclidean(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

int main(){
	ll n,m,k,a;
	while(scanf("%lld %lld %lld %lld", &n, &m, &a, &k), n||m||k||a){
		ll b = a+k-n;
		if(a == 0 || m == 0){
			if(a==m){
				if(b)
					puts("Impossible");
				else
					printf("%lld\n", n);
			}
			else if(a==0){
				if(k>=n&&(k-n)%m==0)
					printf("%lld\n", k);
				else
					puts("Impossible");
			}
			else{
				if(k+a<=n&&(n-k-a)%a==0)
					printf("%lld\n", n);
				else
					puts("Impossible");
			}
		}
		else if(b % __gcd(a, m)){
			puts("Impossible");
		}
		else{
			ll e=0,f;
			if(b < 0){
				ll tmp = -b;
				tmp = tmp / a + (tmp%a>0);
				b += tmp*a;
				e += tmp;
			}
			ll d = b%m;
			if(d > 0){
				f = __gcd(d, a);
				ll g = __gcd(f, m);
				m /= g;
				d /= g;
				ll xx = a / g;
				f = __gcd(d, xx);
				d /= f;
				ll x, y;
				if(extended_euclidean((xx/f)%m, m, x, y)!=1)
					return -121212313;
				ll wew = (-d*x)%m;
                e += (wew + m)%m;
			}
			printf("%lld\n", e * a + a + k);
		}
	}
	return 0;
}