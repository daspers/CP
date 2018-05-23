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
int a[1002];
int dp[1002][1002];

int solve(int id, int rem){
	if(id>=n || rem<=0)
		return 0;
	if(dp[id][rem]==-1){
		dp[id][rem] = solve(id+1, rem);
		if(a[id] <= rem)
			dp[id][rem] = max(dp[id][rem], a[id] + solve(id+2, rem - a[id]));
	}
	return dp[id][rem];
}

int main(){
	scanf("%d", &t);
	for(int cc=1;cc<=t;++cc){
		printf("Scenario #%d: ", cc);
		scanf("%d %d", &n, &m);
		memset(dp, -1, sizeof dp);
		for(i=0;i<n;++i)
			scanf("%d", a+i);
		printf("%d\n", solve(0, m));
	}
	return 0;
}