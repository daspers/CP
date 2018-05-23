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
ll dp[200002], a[200002];

ll solve(int x){
	if(dp[x]==-1){
		dp[x] = 1e18;
		for(int i=1;i<x;i<<=1){
			dp[x] = min(dp[x], llabs(a[x]-a[x-i]) + solve(x-i));
		}
	}
	return dp[x];
}

int main(){
	memset(dp, -1, sizeof dp);
	scanf("%d", &n);
	dp[1]=0;
	for(i=1;i<=n;++i)
		scanf("%lld", a+i);
	printf("%lld\n", solve(n));
	return 0;
}