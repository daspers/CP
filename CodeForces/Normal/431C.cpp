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
int d;
int dp[102][2]; // n depth

int solve(int sisa, int udah){
	int &res = dp[sisa][udah];
	if(res==-1){
		res = 0;
		for(int i=1;i<=k && i<=sisa;++i){
			res += solve(sisa-i, udah|(i>=d));
			res %= mod;
		}
	}
	return res;
}

int main(){
	memset(dp, -1, sizeof dp);
	scanf("%d %d %d", &n, &k, &d);
		dp[0][0] = 0;
		dp[0][1] = 1;
	printf("%d\n", solve(n, 0));
	return 0;
}