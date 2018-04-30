#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int n,m;
ll a[101];
ll dp[101][20001][2];

ll solve(int idx, ll cal, int skip){
	if(idx >= n)
		return 0;
	if(dp[idx][cal][skip]==-1){
		if(skip){
			dp[idx][cal][skip] = max(
					min(a[idx], cal) + solve(idx+1, (cal*2.0)/3, 0),		// ngambil
					max( max(solve(idx+1, m, 0), solve(idx+1, m, 1)),							// skip 1
						max(solve(idx+2, m, 0), solve(idx+2, m, 1))								// skip 2
					));
		}
		else{
			dp[idx][cal][skip] =  max(
					min(a[idx], cal) + solve(idx+1, (cal*2.0)/3, 0),		// ngambil
					max(solve(idx+1, cal, 1),							// skip 1
						max(solve(idx+2, m, 0), solve(idx+2, m, 1))								// skip 2
					));
		}
	}
	return dp[idx][cal][skip];
}

int main(){
	memset(dp, -1, sizeof dp);
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++){
		scanf("%lld", a+i);
	}
	printf("%lld\n", max(solve(0, m, 0), solve(0,m,1)));
	return 0;
};