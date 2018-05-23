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
int a[3];
int dp[4002];

int main(){
	scanf("%d %d %d %d", &n, a, a+1, a+2);
	sort(a, a+3);
	if(a[0]==1){
		printf("%d\n", n);
		return 0;
	}
	dp[0] = 1;
	for(i=1;i<=n;++i){
		dp[i]=0;
		int b,c,d;
		b=c=d=0;
		if(a[0]<=i){
			b = dp[i-a[0]];
			if(b)
				dp[i] = max(dp[i], b+1);
		}
		if(a[1]<=i){
			c = dp[i-a[1]];
			if(c)
				dp[i] = max(dp[i], c+1);
		}
		if(a[2]<=i){
			d = dp[i-a[2]];
			if(d)
				dp[i] = max(dp[i], d+1);
		}
		// cout<<i<<" "<<b<<" "<<c<<" "<<d<<" "<<endl;
	}
	printf("%d\n", dp[n]-1);
	return 0;
}