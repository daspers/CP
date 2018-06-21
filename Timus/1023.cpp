#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define INF 200000001
#define EPS 1e-9

typedef long long ll;
typedef complex<double> cd;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
int dp[100002];

int solve(int id){
	if(dp[id]==-1){
		dp[id] = 0;
		for(int i=1;i<=t && i<=id;++i){
			dp[id] = max(dp[id], 1^solve(id-i));
		}
	}
	return dp[id];
}

void findpattern(){
	for(t=2;t<n;++t){
		memset(dp, -1, sizeof dp);
		dp[0] = 0;
		printf("%d", t);
		for(i=1;i<=n;++i){
			printf(" %d", solve(i));
		}
		puts("");
	}
}

int main(){
	scanf("%d", &n);
	// findpattern();
	for(int i=3;i<=n;++i){
		if(n%i==0){
			printf("%d\n", i-1);
			return 0;
		}
	}
	return 0;
}
