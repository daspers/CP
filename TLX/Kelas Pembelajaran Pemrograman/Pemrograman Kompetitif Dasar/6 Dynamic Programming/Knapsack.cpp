#include <bits/stdc++.h>

using namespace std;

int n,k, x,y,i, dp[103][2003], j;
pair<int, int> c[103];
vector<int> m;

int main(){
	scanf("%d %d", &k, &n);
	for(i=0;i<n;i++){
		scanf("%d %d", &x, &y);
		c[i] = make_pair(x,y);
	}
	memset(dp, 0, sizeof(dp));
	for(i=0;i<n;i++){
		if(i>0){
			for(j=1;j<=k;j++){
				if(j>=c[i].first){
					if(c[i].second + dp[i-1][j-c[i].first] > dp[i-1][j])
						dp[i][j] = c[i].second+ dp[i-1][j-c[i].first];
					else
						dp[i][j] = dp[i-1][j];
				}
				else
					dp[i][j] = dp[i-1][j];
			}
		}
		else{
			for(j=1;j<=k;j++){
				if(j>=c[i].first)
					dp[i][j] = c[i].second;

				else
					dp[i][j] = dp[i][j-1];
			}
		}
	}
	for(i=n-1; i>0;i--){
		if(dp[i][k] != dp[i-1][k]){
			m.push_back(i+1);
			k-=c[i].first;
		}
	}
	if(dp[i][k]>0)
		m.push_back(1);
	sort(m.begin(), m.end());
	for(i=0; i<m.size();i++)
		printf("%d\n", m[i]);
	return 0;
}
