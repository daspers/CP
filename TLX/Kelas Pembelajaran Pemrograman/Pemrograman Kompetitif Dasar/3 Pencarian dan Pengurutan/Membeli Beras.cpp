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
int a[100002], c[100002], w[100002];
pair<double, int> wew[100002];

int main(){
	scanf("%d %d", &n, &k);
	for(i=0;i<n;++i)
		scanf("%d", w+i);
	for(i=0;i<n;++i)
		scanf("%d", c+i);
	for(i=0;i<n;++i)
		wew[i] = {1.0*c[i]/w[i], w[i]};
	sort(wew, wew+n, greater<pair<double, int>>());
	double ans = 0;
	for(i=0;k>0&&i<n;++i){
		int tmp = min(wew[i].se, k);
		ans += wew[i].fi * tmp;
		k -= tmp;
	}
	printf("%.9lf\n", ans);
	return 0;
}