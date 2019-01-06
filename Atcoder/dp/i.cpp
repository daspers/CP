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
double p[3002];
double dp[3002][3002];

int main(){
    scanf("%d", &n);
    for(i=1;i<=n;++i)
        scanf("%lf", p+i);
    int val = n - (n-1)/2;
    for(j=0;j<=n;++j)
        dp[0][j] = 0;
    dp[0][0] = 1;
    for(i=1;i<=n;++i){
        for(j=0;j<=n;++j)
            dp[i][j] = 0;
        for(j=0;j<i;++j){
            dp[i][j+1] += p[i]*dp[i-1][j];
            dp[i][j] += (1-p[i])*dp[i-1][j];
        }
    }
    double ans = 0;
    for(i=val;i<=n;++i)
        ans += dp[n][i];
    printf("%.12lf\n", ans);
}