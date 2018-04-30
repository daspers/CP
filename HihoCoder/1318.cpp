#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define baca getchar_unlocked

typedef long long ll;
 
const int mod = 1e9+7;
const double pi = acos(-1);


int n,t,i,j,k;
ll dp[102];
ll p2[102];
ll fib[102];

int main(){
	scanf("%d", &n);
	dp[1] = 0;
	for(i=2;i<102;i++)
		dp[i] = (1+2*dp[i-1])%mod;
	p2[0] = 1;
	for(i=1;i<101;i++)
		p2[i] = (2*p2[i-1])%mod;
	int ans = p2[n];
	fib[1] = 2;
	fib[2] = 3;
	for(i=3;i<101;i++){
		fib[i] = (fib[i-1] + fib[i-2])%mod;
	}
	ans -= fib[n];
	if(ans<0)
		ans += mod;
	printf("%d\n", ans);
	return 0;
}