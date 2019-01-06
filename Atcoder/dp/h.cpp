#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef long long ll;

const int mod = 1e9+7;

int n, i, j;
int m;
char s[1001][1002];
int dp[1001][1001];

int main(){
    memset(dp, 0, sizeof dp);
    scanf("%d %d",&n, &m);
    for(i=0;i<n;++i){
        scanf("%s", s[i]);
    }
    dp[0][0] = 1;
    for(i=1;i<m;++i){
        if(s[0][i]=='#') break;
        dp[0][i] = 1;
    }
    for(i=1;i<n;++i){
        if(s[i][0]=='#') break;
        dp[i][0] = 1;
    }
    for(i=1;i<n;++i){
        for(j=1;j<m;++j){
            if(s[i][j]=='#') continue;
            dp[i][j] = (dp[i][j-1]+dp[i-1][j])%mod;
        }
    }
    int ans = dp[n-1][m-1];
    printf("%d\n", ans);
    return 0;
}