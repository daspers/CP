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
int dp[20];

int main(){
	scanf("%d %d", &n, &k);
	k--;
	dp[0] = 1;
	dp[1] = k;
	for(i=2;i<=n;++i)
		dp[i] = k*(dp[i-1]+dp[i-2]);
	printf("%d\n", dp[n]);
	return 0;
}
