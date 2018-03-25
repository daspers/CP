#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
 
const ll mod = 1e9+7;
const double pi = acos(-1);

int n,t,j,i,k;
ll a[100003], b[100003], c[100003], p[100003];
ll dp[100003][4];

int main(){
	scanf("%d", &n);
	for(i=0;i<n;i++)
		scanf("%lld", a+i);
	for(i=0;i<n;i++)
		scanf("%lld", b+i);
	for(i=0;i<n;i++)
		scanf("%lld", c+i);
	for(i=1;i<n;i++)
		scanf("%lld", p+i);
	dp[0][0] = a[0];
	dp[0][1] = b[0];
	dp[0][2] = c[0];
	for(int i=1;i<n;i++){
		dp[i][0] = dp[i-1][0]+a[i];
		dp[i][1] = dp[i-1][1]+b[i];
		dp[i][2] = dp[i-1][2]+c[i];
		ll x = min(dp[i-1][1]+a[i], dp[i-1][2]+a[i])+p[i];
		if(x<dp[i][0]){
			dp[i][0]= x;
		}
		x = min(dp[i-1][0]+b[i], dp[i-1][2]+b[i])+p[i];
		if(x<dp[i][1]){
			dp[i][1]= x;
		}
		x = min(dp[i-1][0]+c[i], dp[i-1][1]+c[i])+p[i];
		if(x<dp[i][2]){
			dp[i][2]= x;
		}
	}
	printf("%lld\n", min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2])));
	return 0;
}