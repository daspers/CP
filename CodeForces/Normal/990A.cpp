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

ll n,i,j,k,t;
ll a, b, m;

int main(){
	scanf("%lld %lld %lld %lld", &n, &m, &a, &b);
	ll lb = n/m;
	ll ub = n/m+1;
	printf("%lld\n", min((n-lb*m)*b,(ub*m-n)*a));
	return 0;
}
