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
int dp[3002], a[3002];
ll ma[3002];
ll psum[3002];

int main(){
	memset(dp, 0, sizeof dp);
	memset(ma, 0, sizeof ma);
	scanf("%d", &n);
	psum[0] = 0;
	for(i=1;i<=n;++i){
		scanf("%d", a+i);
		psum[i] = psum[i-1] + a[i];
	}
	dp[1] = 1;
	ma[1] = a[1];
	for(i=2;i<=n;++i){
		for(j=0;j<i;++j){
			if(ma[j] <= psum[i] - psum[j]){
				if(dp[j] + 1 > dp[i]){
					dp[i] = dp[j]+1;
					ma[i] = psum[i] - psum[j];
				}
				else if(dp[j] + 1 == dp[i]){
					ma[i] = min(ma[i], psum[i] - psum[j]);
				}
			}
		}
	}
	printf("%d\n", dp[n]);
	return 0;
}