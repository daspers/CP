#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-8
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define FastSlowInput ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
ll a[500002];
set<ll> *b, *c, d;

int main(){
	scanf("%d", &n);
	for(i=1;i<=n;++i)
		scanf("%lld", a+i);
	b = new set<ll>();
	for(i=1;i<=n;++i){
		c = new set<ll>();
		c->insert(a[i]);
		for(ll x : *b)
			 c->insert(__gcd(x, a[i]));
		d.insert(c->begin(), c->end());
		delete b;
		b = c;
		c = NULL;
	}
	printf("%d\n", (int)d.size());
	return 0;
}
