#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, i, j;
int w;
ll dp[101][100001];

int main(){
    scanf("%d %d", &n, &w);
    memset(dp, 0, sizeof dp);
    for(i=1;i<=n;++i){
        int a, b;
        scanf("%d %d", &a, &b);
        for(j=0;j<=w;++j)
            dp[i][j]=dp[i-1][j];
        for(j=a;j<=w;++j){
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-a]+b);
        }
    }
    printf("%lld\n", *max_element(dp[n], dp[n]+w+1));
    return 0;
}