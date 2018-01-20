#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>

typedef long long ll;

int const mod = 1e9+7;

typedef struct{
	int r;
	int t;
	int u;
}order;

int n,i,j,k,t,r,e,w;
order a[25];
int dp[23][310][310];
vector<int> ans;

int main(){
	scanf("%d %d %d", &n, &w, &e);
	for(i=1;i<=n;i++)
		scanf("%d %d %d", &a[i].r, &a[i].u, &a[i].t);
	memset(dp, -1, sizeof dp);
	for(i=0;i<=n;i++){
		for(j=0;j<=e;j++){
			for(k=0;k<=w;k++){
				if(i==0||j==0||k==0)
					dp[i][j][k]=0;
				else if(a[i].u<=j && a[i].t<=k){
					dp[i][j][k] = max(a[i].r+dp[i-1][j-a[i].u][k-a[i].t],dp[i-1][j][k]);
				}
				else
					dp[i][j][k] = dp[i-1][j][k];
			}
		}
	}
	if(dp[n][e][w]==0){
		for(i=n,j=e,k=w;i>0;i--){
			if(dp[i][j][k]!=dp[i-1][j][k]){
				ans.pb(i);
				j-=a[i].u;
				k-=a[i].t;
			}
		}
		sort(ans.begin(), ans.end());
		printf("%d", ans[0]);
		for(i=1;i<ans.size();i++){
			printf(" %d", ans[i]);
		}
	}
	puts("");
	return 0;
}
