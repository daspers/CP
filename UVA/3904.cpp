#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define Nmax 300000 

typedef long long ll;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t,m;
int dp[50];

int main(){
	dp[0]=1; dp[1]=1;
	dp[2]=3;
	for(i=3;i<=30;++i)
		dp[i] = dp[i-1]+2*dp[i-2];
	for(i=30;i>2;--i){
		if(i&1)
			dp[i] += dp[i/2];
		else
			dp[i] += 2*dp[i/2-1]+dp[i/2];
		dp[i]/=2;
	}
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%d\n", dp[n]);
	}
	return 0;
}