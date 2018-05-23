#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define Nmax 300000 

typedef unsigned long long ll;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t,m;
ll dp[502][502];

ll solve(int sisa, int ma){
	if(dp[sisa][ma]==-1){
		ll ans = 0;
		for(int i=ma;i>0;--i){
			ans += solve(sisa-i, min(sisa-i, i-1));
		}
		dp[sisa][ma] = ans;
	}
	return dp[sisa][ma];
}

int main(){
	memset(dp, -1, sizeof dp);
	dp[0][0] = 1;
	dp[1][1] = 1;
	dp[2][2] = 1;
	for(i=1;i<=500;++i){
		dp[i][0] = 0;
		dp[0][i] = 1;
	}
	scanf("%d", &n);
	printf("%llu\n", solve(n, n-1));
	return 0;
}