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
// typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;

const ll mod = 1e9+7;
const double PI = acos(-1);

int n,i,j,k,t;
int a[202];
int dp[201][50002];

int solve(int idx, int sisa){
	int &ans = dp[idx][sisa];
	if(ans==-1){
		ans = solve(idx+1, sisa);
		if(a[idx] <= sisa)
			ans = max(ans, a[idx]+solve(idx+1, sisa - a[idx]));
	}
	return ans;
}

int main(){
	scanf("%d", &t);
	while(t--){
		memset(dp, -1, sizeof dp);
		scanf("%d", &n);
		int sum = 0;
		for(i=1;i<=n;++i){
			scanf("%d", a+i);
			sum += a[i];
		}
		reverse(a+1, a+n+1);
		for(i=0;i<=sum/2;++i)
			dp[0][i] = 0;
		for(i=1;i<=n;++i){
			for(j=0;j<=sum/2;++j)
				dp[i][j] = dp[i-1][j];
			for(j=a[i];j<=sum/2;++j)
				dp[i][j] = max(dp[i][j], a[i]+dp[i-1][j-a[i]]);
		}
		int sel = sum - 2*dp[n][sum/2];
		ll area = 1LL*(sum+sel)/2 * (sum-sel)/2;
		int sisa = sum/2;
		
		printf("%lld\n", area);
		for(i=n;i>0;--i){
			if(a[i]<=sisa && dp[i][sisa]==a[i]+dp[i-1][sisa-a[i]]){
				printf("D");
				sisa -= a[i];
			}
			else
				printf("R");
		}
		puts("");
	}
	return 0;
}