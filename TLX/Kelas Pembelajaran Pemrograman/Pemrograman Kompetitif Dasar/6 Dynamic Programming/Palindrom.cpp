#include <bits/stdc++.h>

using namespace std;

int n, dp[55][55;
string s;

int palindrom(int l, int r){
	if(l>r)
		return 0;
	if(l==r)
		return 1;
	if(dp[l][r] == -1){
		if(s[l]==s[r])
			dp[l][r] = palindrom(l+1, r-1)+2;
		else
			dp[l][r] = max(palindrom(l+1,r), palindrom(l,r-1));
	}
	return dp[l][r];
}

int main(){
	scanf("%d", &n);
	while(n--){
		cin>>s;
		memset(dp, -1, sizeof(dp));
		printf("%d\n", palindrom(0,s.size()-1));
	}
	return 0;
}
