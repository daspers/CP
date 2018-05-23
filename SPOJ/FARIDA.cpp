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
ll dp[10002], a[10002];

ll solve(int x){
	if(x<=0)
		return 0;
	if(dp[x]==-1){
		dp[x] = max(solve(x-1), a[x] + solve(x-2));
	}
	return dp[x];
}

int main(){
	scanf("%d", &t);
	for(int cc=1;cc<=t;++cc){
		printf("Case %d: ", cc);
		scanf("%d", &n);
		memset(dp, -1, (n+1)<<3);
		dp[0]=0;
		for(i=1;i<=n;++i)
			scanf("%lld", a+i);
		printf("%lld\n", solve(n));
	}
	return 0;
}