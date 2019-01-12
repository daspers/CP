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
char s[3005];
int dp[3003][3003];
int sum[3003];


int main(){
    memset(dp, 0, sizeof dp);
    scanf("%d", &n);
    scanf("%s", s+2);
    dp[1][1] = 1;
    for(i=2;i<=n;++i){
        sum[0] = 0;
        for(j=1;j<=n;++j)
            sum[j] = (sum[j-1] + dp[i-1][j]) % mod;
        for(j=1;j<=i;++j){
            if(s[i] == '>')
                dp[i][j] = (mod + sum[n] - sum[j-1]) % mod;
            else
                dp[i][j] = sum[j-1];
        }
    }
    sum[0] = 0;
    for(i=1;i<=n;++i)
        sum[i] = (sum[i-1] + dp[n][i]) % mod;
    printf("%d\n", sum[n]);
    return 0;
}