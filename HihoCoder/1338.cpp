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
int a[1001];
int dp[1001][1001];
int pre[1005];

int solve(int l, int r){
	if(dp[l][r] > 1000000){
		dp[l][r] = max(pre[r+1]-pre[l] - solve(l+1, r),
		               pre[r+1]-pre[l] - solve(l, r-1));
	}
	return dp[l][r];
}

int main(){
	for(i=0;i<=1000;i++)
		for(j=0;j<=1000;j++)
			dp[i][j] = 10000000;
	scanf("%d", &n);
	pre[0]=0;
	for(i=0;i<n;i++){
		scanf("%d", a+i);
		dp[i][i] = a[i];
		pre[i+1] = pre[i]+a[i];
	}
	printf("%d\n", solve(0, n-1));
	return 0;
}