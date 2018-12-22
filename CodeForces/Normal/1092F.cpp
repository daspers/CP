#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-9
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9+7;
const double PI = acos(-1);

int n,i,j,k,t;
int a[200003];
ll sums;
vector<int> adj[200003];
ll sum[200003];
ll dp[200003];
ll ans[200003];

void dfs(int v, int p){
    sum[v] = a[v];
    dp[v] = 0;
    for(int x : adj[v]){
        if(x == p) continue;
        dfs(x, v);
        sum[v] += sum[x];
        dp[v] += dp[x] + sum[x];
    }
}

void dfs2(int v, int p){
    if(v != p){
        ans[v] = ans[p] + sum[1] - 2*sum[v];
    }
    else ans[v] = dp[v];
    for(int x : adj[v]){
        if(x == p) continue;
        dfs2(x, v);
    }
}

int main(){
    scanf("%d", &n);
    for(i=1;i<=n;++i){
        scanf("%d", a+i);
    }
    for(i=1;i<n;++i){
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1,1);
    dfs2(1,1);
    printf("%lld\n", *max_element(ans+1, ans+1+n));
	return 0;
}