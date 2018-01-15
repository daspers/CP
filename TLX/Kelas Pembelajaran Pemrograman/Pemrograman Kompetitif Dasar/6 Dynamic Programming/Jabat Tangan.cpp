#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;

ll n, dp[55];

ll jabat(ll a){
	if(dp[a]==-1){
		dp[a] = 0;
		if(a%2==0){
			for(ll i=0;i<a;i+=2)
				dp[a]+=jabat(i)*jabat(a-i-2);
		}
	}
	return dp[a];
}

int main(){
	scanf("%lld", &n);
	memset(dp, -1, sizeof(dp));
	dp[0] = 1;
	dp[2] = 1;
	printf("%lld\n", jabat(n));
	return 0;
}
