#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>

typedef long long ll;

int const mod = 1e9+7;

int n,i,j,k,t,r,a,b,c,d;
vector<string> v;
string s;
pair<int, int> **dp;
queue<pair<int, int> >  q;
int x[4]={0,0,1,-1}, y[4]={1,-1,0,0};

int main(){
	scanf("%d %d", &n, &k);
	dp = new pair<int, int>*[n+3];
	for(i=0;i<n+3;i++){
		dp[i] = new pair<int, int>[n+3];
	}
	for(i=0;i<n;i++){
		cin>>s;
		v.pb(s);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(v[i][j]=='R'){
				a = i, b=j;
			}
			if(v[i][j]=='S'){
				c = i, d=j;
			}
			dp[i][j]={-1,-1};
		}
	}
	dp[a][b] = {0,0};
	q.push({a,b});
	while(!q.empty()){
		pair<int, int> temp = q.front();
		q.pop();
		for(i=0;i<4;i++){
			int g = temp.fi + x[i];
			int h = temp.se + y[i];
			if(g>=0&&h>=0&&g<n&&h<n){
				int pag = v[g][h] == '#';
				if(dp[g][h].fi==-1){
					if(dp[temp.fi][temp.se].se+pag<=k){
						dp[g][h] = {1 + dp[temp.fi][temp.se].fi, dp[temp.fi][temp.se].se+pag};
						q.push({g,h});
					}
				}
				else if(dp[temp.fi][temp.se].se+pag <=k){
					if(dp[g][h].fi>dp[temp.fi][temp.se].fi+1){
						dp[g][h] = {1 + dp[temp.fi][temp.se].fi, dp[temp.fi][temp.se].se+pag};
						q.push({g,h});
					}
					else if(dp[g][h].fi==dp[temp.fi][temp.se].fi+1)
						if(dp[g][h].se>dp[temp.fi][temp.se].se+pag){
							dp[g][h].se = dp[temp.fi][temp.se].se+pag;
							q.push({g,h});
						}
				}
			}
		}
	}
	if(dp[c][d].fi==-1)
		puts("IMPOSSIBLE");
	else
		printf("%d\n", dp[c][d].fi);
	return 0;
}
