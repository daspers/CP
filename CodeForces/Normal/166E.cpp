#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define baca getchar_unlocked

typedef long long ll;
 
const int mod = 1e9+7;
const double pi = acos(-1);


int n,t,i,j,k;
ll dp[2][10000001];


int main(){
	scanf("%d", &n);
	dp[0][0] = 1;
	dp[1][0] = 0;
	for(i=1;i<=n;i++){
		dp[0][i] = (3*dp[1][i-1])%mod;
		dp[1][i] = (dp[0][i-1] + 2*dp[1][i-1])%mod;
	}
	printf("%d\n", dp[0][n]);
	return 0;
}