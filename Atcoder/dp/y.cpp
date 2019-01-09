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
int h,w;
int fact[200002];
int ifact[200002];
pii p[3002];
int dp[3002];

int powmod(int a, int b){
    int ans = 1;
    for(;b;b>>=1){
        if(b&1){
            ans = 1LL*ans*a%mod;
        }
        a = 1LL*a*a%mod;
    }
    return ans;
}

int combin(int a, int b){
    int ans = 1LL*fact[a]*ifact[b] % mod;
    ans = 1LL*ans*ifact[a-b] % mod;
    return ans;
}

int main(){
    fact[0] = ifact[0] = 1;
    for(i=1;i<=200000;++i){
        fact[i] = 1LL*i*fact[i-1] % mod;
        ifact[i] = 1LL*powmod(i, mod-2)*ifact[i-1] % mod;
    }
    scanf("%d %d %d", &h, &w, &n);
    for(i=1;i<=n;++i)
        scanf("%d %d", &p[i].fi, &p[i].se);
    p[0] = {1,1};
    p[n+1] = {h, w};
    sort(p, p+n+2);
    memset(dp, 0, sizeof dp);
    dp[0] = 0;
    for(i=1;i<=n+1;++i){
        dp[i] = combin(p[i].fi+p[i].se-2, p[i].fi-1);
        for(j=1;j<i;++j){
            if(p[j].se > p[i].se) continue;
            dp[i] -= 1LL*combin(p[i].fi+p[i].se-p[j].fi-p[j].se, p[i].fi - p[j].fi) * dp[j] % mod;
            dp[i] %= mod;
        }
    }
    if(dp[n+1] < 0)
        dp[n+1] += mod;
    printf("%d\n", dp[n+1]);
    return 0;
}