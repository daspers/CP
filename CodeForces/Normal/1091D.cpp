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
int fact[1000002];
int dp[1000002];

int main(){
	scanf("%d", &n);
    fact[0] = 1;
    for(i=1;i<=n;++i)
        fact[i] = 1LL*i*fact[i-1] % mod;
    dp[1] = 0;
    for(i=2;i<=n;++i){
        dp[i] = (1LL*i * dp[i-1] % mod + 1LL*(i-1)*(i-1) % mod) % mod;
    }
    int ans = 1LL*n*fact[n] % mod;
    ans -= n-1;
    ans -= dp[n];
    ans %= mod;
    if(ans < 0)
        ans += mod;
    printf("%d\n", ans);
	return 0;
}