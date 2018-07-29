#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-9
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"

typedef long long ll;
typedef complex<double> cd;
typedef pair<int, int> pii;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
int m;
int dp[1001][5001];
int c[1002], w[1002];

int solve(int idx, int rem){
	if(dp[idx][rem] == -1){
		dp[idx][rem] = solve(idx+1, rem);
		for(int i=0;i*w[idx]<=rem;++i)
			dp[idx][rem] = max(dp[idx][rem], c[idx]*i+solve(idx+1, rem-i*w[idx]));
	}
	return dp[idx][rem];
}

int main(){
	memset(dp, -1, sizeof dp);
	scanf("%d %d", &n, &m);
	for(i=0;i<n;++i)
		scanf("%d %d", w+i, c+i);
	for(i=0;i<=m;++i)
		dp[n][i] = 0;
	printf("%d\n", solve(0, m));
	return 0;
}