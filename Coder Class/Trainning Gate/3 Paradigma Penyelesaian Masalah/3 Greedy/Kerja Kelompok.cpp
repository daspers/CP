#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-9
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"

typedef long long ll;
typedef complex<double> cd;
typedef pair<int, int> pii;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
ll a[100002];
// int dp[1002][30002];

int main(){
	// memset(dp, -1, sizeof dp);
	scanf("%d", &n);
	for(i=0;i<n;++i)
		scanf("%lld", a+i);
	if(n==1){
		printf("%lld\n", a[0]);
		return 0;
	}
	sort(a, a+n);
	ll sum =0;
	for(i=0;i<n;++i)
		sum +=a[i];
	if(a[n-1] > sum - a[n-1])
		printf("%lld\n", 2*a[n-1]-sum);
	else
		printf("%lld\n", sum&1);
	return 0;
}