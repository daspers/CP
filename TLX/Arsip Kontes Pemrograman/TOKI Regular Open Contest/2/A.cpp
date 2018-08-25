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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 998244353;
const double pi = acos(-1);

int n,i,j,k,t;
int m,a,b;

int main(){
	scanf("%d %d", &n, &m);
	scanf("%d %d", &a, &b);
	printf("%d\n", max((n/a)*(m/b), (n/b)*(m/a)));
	return 0;
}