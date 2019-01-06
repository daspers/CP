#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, i, j;
int w;
ll dp[101][100001];

int main(){
    scanf("%d %d", &n, &w);
    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;
    for(i=1;i<=n;++i){
        int a, b;
        scanf("%d %d", &a, &b);
        memcpy(dp[i], dp[i-1], sizeof dp[i]);
        for(j=b;j<=100000;++j){
            if(dp[i-1][j-b] == -1) continue;
            if(dp[i][j] == -1)
                dp[i][j] = dp[i-1][j-b]+a;
            else
                dp[i][j] = min(dp[i][j], dp[i-1][j-b]+a);
        }
    }
    for(i=100000;i>=0;--i)
        if(dp[n][i]!=-1 && dp[n][i]<=w){
            printf("%lld\n", i);
            break;
        }
    return 0;
}