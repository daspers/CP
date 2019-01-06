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
int a[102];
int dp[101][100002];
int psum[101][100002];

int main(){
    memset(dp, 0, sizeof dp);
    scanf("%d %d", &n, &k);
    dp[0][0] = 1;
    for(i=1;i<=n;++i)
        scanf("%d", a+i);
    for(i=1;i<=n;++i){
        psum[i-1][0] = 1;
        for(j=1;j<=k;++j){
            psum[i-1][j] = (dp[i-1][j] + psum[i-1][j-1])%mod;
        }
        for(j=0;j<=k;++j){
            if(a[i] >= j){
                dp[i][j] = (dp[i][j] + psum[i-1][j])%mod;
            }
            else{
                dp[i][j] += (mod + psum[i-1][j] - psum[i-1][j-a[i]-1] )%mod;
                dp[i][j] %= mod;
            }
        }
    }
    int ans = dp[n][k];
    printf("%d\n", ans);
    return 0;
}