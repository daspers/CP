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
pair<pii, int> a[1004];
ll dp[1003][20002];

ll solve(int idx, int rem){
    ll &ans = dp[idx][rem];
    if(ans == -1){
        ans = solve(idx+1, rem);
        if(rem >= a[idx].fi.fi)
            ans = max(ans, a[idx].se + solve(idx+1, min(rem - a[idx].fi.fi, a[idx].fi.se)));
    }
    return ans;
}

int main(){
    scanf("%d", &n);
    for(i=0;i<n;++i)
        scanf("%d %d %d", &a[i].fi.fi, &a[i].fi.se, &a[i].se);
    sort(a, a+n, [](const pair<pii, int> &a, const pair<pii, int> &b) -> bool{
        return a.fi.fi+a.fi.se > b.fi.fi+b.fi.se;
    });
    memset(dp, -1, sizeof dp);
    memset(dp[n], 0, sizeof dp[n]);
    ll ans = solve(0, 2e4);
    printf("%lld\n", ans);
    return 0;
}