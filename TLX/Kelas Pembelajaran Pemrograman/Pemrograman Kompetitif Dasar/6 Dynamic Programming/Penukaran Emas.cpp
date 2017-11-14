#include <bits/stdc++.h>

using namespace std;

int n, dp[1003];

int berat(int a){
	if(dp[a]==-1)
		dp[a] = max(a, berat(a/4)+berat(a/3)+berat(a/2));
	return dp[a];
}

int main(){
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	printf("%d\n", berat(n));
	return 0;
}
