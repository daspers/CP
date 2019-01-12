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

const ll mod = 998244353 ;
const double PI = acos(-1);

int n,i,j,k,t;
ll dp[1<<17];
ll cost[1<<17];
int a[17][17];
bool visdp[1<<17];
bool viscost[1<<17];

ll totcost(int mask){
    ll &ans = cost[mask];
    if(viscost[mask]){
        viscost[mask] = false;
        ans = 0;
        int i = __builtin_ffs(mask) - 1;
        for(int j=i+1;j<n;++j){
            if(mask & (1<<j))
                ans += a[i][j];
        }
        ans += totcost(mask ^ (1<<i));
    }
    return ans;
}

ll solve(int mask){
    ll &ans = dp[mask];
    if(visdp[mask]){
        visdp[mask] = false;
        ans = -1e18;
        for(int sub = mask;sub;sub=(sub-1)&mask){
            ans = max(ans, totcost(sub) + solve(mask ^ sub));
        }
    }
    return ans;
}

int main(){
    memset(dp, 0, sizeof dp);
    memset(visdp, true, sizeof visdp);
    memset(viscost, true, sizeof viscost);
    memset(cost, 0, sizeof cost);
    scanf("%d", &n);
    for(i=0;i<n;++i){
        for(j=0;j<n;++j){
            scanf("%d", a[i]+j);
        }
    }
    visdp[0] = viscost[0] = 0;
    for(i=0;i<n;++i)
        visdp[1<<i] = viscost[1<<i] = 0;
    ll ans = solve((1<<n)-1);
    printf("%lld\n", ans);
	return 0;
}