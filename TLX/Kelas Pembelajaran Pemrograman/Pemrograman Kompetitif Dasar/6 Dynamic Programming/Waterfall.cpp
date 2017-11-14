#include <bits/stdc++.h>

using namespace std;

long n,t,d,k,m[502][502], xa,ya, xb,yb, dp[502][502], ma,v,h,i,j;

long findp(long l, long r){
	if(l == v+1 || r == 0 || r == h+1)
		return 0;
	if(dp[l][r] == -1){
		if(m[l+1][r] == 1){
			if(m[l+1][r-1] == 1 && dp[l][r-1]!=-1){
				dp[l][r] = dp[l][r-1];
			}
			else if(m[l+1][r+1] == 1 && dp[l][r+1]!=-1)
				dp[l][r] = dp[l][r+1];
			else{
				long w = r+1, x = r-1;
				while(m[l+1][w] == 1)
					w++;
				while(m[l+1][x] == 1)
					x--;
				dp[l][r] = 1 + findp(l,x) + findp(l,w);
			}
		}
		else{
			dp[l][r] = findp(l+1, r);
		}
	}
	return dp[l][r];
}

int main(){
	scanf("%ld %ld %ld", &v, &h, &n);
	memset(m, 0, sizeof(m));
	for(i=0; i<n;i++){
		scanf("%ld %ld %ld %ld", &xa, &ya, &xb, &yb);
		for(j=xa;j<=xb;j++){
			for(k=ya;k<=yb;k++)
				m[j][k] = 1;
		}
	}
	memset(dp, -1, sizeof(dp));
	ma=0;
	for(i=1;i<=h;i++){
		ma = max(ma, findp(0, i));
	}
	printf("%ld\n", ma);
	return 0;
}
