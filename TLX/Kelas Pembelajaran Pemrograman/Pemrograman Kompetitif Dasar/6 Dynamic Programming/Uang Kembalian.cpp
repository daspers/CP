// Some people call this technique as DP 'Flying Table'

#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

int n, c[503], p,i,j, dp[2][50001];

int main(){
	scanf("%d", &n);
	for(i=0;i<n;i++)
		scanf("%d", c+i);
	scanf("%d", &p);
	sort(c, c+n, greater<int>());
	for(i=0;i<n;i++)
		dp[i&1][0] = 0;
	for(i=0;i<=p;i++)
		dp[n&1][i] = 999999;
	for(i=n-1;i>=0;i--){
		for(j=1;j<=p;j++){
			if(j>=c[i])
				dp[i&1][j] = min(dp[(i+1)&1][j], dp[i&1][j-c[i]]+1);
			else
				dp[i&1][j] = dp[(i+1)&1][j];
		}
	}
	printf("%d\n", dp[0][p]);
	return 0;
}
