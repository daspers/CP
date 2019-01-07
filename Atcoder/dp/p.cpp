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
vector<int> adj[100002];
int dp[100002][2];

int solve(int v, int p, int c){
    int &ans = dp[v][c];
    if(ans == -1){
        ans = 0;
        if(c == 1){
            ans = 1;
            for(int x : adj[v]){
                if(x == p) continue;
                ans = 1LL*ans*solve(x, v, 0) % mod;
            }
        }
        else{
            ans = 1;
            for(int x : adj[v]){
                if(x == p) continue;
                ans = 1LL*ans*(solve(x, v, 0) + solve(x, v, 1))%mod ;
            }
        }
    }
    return ans;
}

int main(){
    memset(dp, -1, sizeof dp);
    scanf("%d", &n);
    for(i=1;i<n;++i){
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int ans = (solve(n, n, 0) + solve(n, n, 1)) % mod;
    printf("%d\n", ans);
    return 0;
}