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
int a[100002];

int main(){
	scanf("%d", &n);
	for(i=0;i<n;++i)
		scanf("%d", a+i);
	sort(a, a+n);
	printf("%.1lf\n", (a[n/2] + a[(n-1)/2])/2.0);
	return 0;
}