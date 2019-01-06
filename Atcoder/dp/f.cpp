#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef long long ll;

int n, i, j;
int m;
vector<int> adj[100002];
int dp[100002];

int dfs(int v){
    int &ans = dp[v];
    if(ans == -1){
        ans = 0;
        for(int x : adj[v])
            ans = max(ans, 1+dfs(x));
    }
    return ans;
}

int main(){
    memset(dp, -1, sizeof dp);
    scanf("%d %d",&n, &m);
    for(i=0;i<m;++i){
        int a, b;
        scanf("%d %d", &a ,&b);
        adj[a].pb(b);
    }
    int ans = 0;
    for(i=1;i<=n;++i){
        ans = max(ans, dfs(i));
    }
    printf("%d\n", ans);
    return 0;
}