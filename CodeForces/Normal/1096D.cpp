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
int a[100005];
char s[100005];
ll dp[100005][5];

int main(){
    scanf("%d", &n);
    scanf("%s", s+1);
    for(i=1;i<=n;++i){
        scanf("%d", a+i);
    }
    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;
    for(i=1;i<=n;++i){
        if(s[i] == 'h'){
            if(dp[i-1][0] != -1)
                dp[i][0] = a[i] + dp[i-1][0];
            if(dp[i-1][0] == -1)
                dp[i][1] = dp[i-1][1];
            else if(dp[i-1][1] == -1)
                dp[i][1] = dp[i-1][0];
            else
                dp[i][1] = min(dp[i-1][0], dp[i-1][1]);
            dp[i][2] = dp[i-1][2];
            dp[i][3] = dp[i-1][3];
            dp[i][4] = dp[i-1][4];
        }
        else if(s[i] == 'a'){
            dp[i][0] = dp[i-1][0];
            if(dp[i-1][1] != -1)
                dp[i][1] = a[i] + dp[i-1][1];
            if(dp[i-1][1] == -1)
                dp[i][2] = dp[i-1][2];
            else if(dp[i-1][2] == -1)
                dp[i][2] = dp[i-1][1];
            else
                dp[i][2] = min(dp[i-1][1], dp[i-1][2]);
            dp[i][3] = dp[i-1][3];
            dp[i][4] = dp[i-1][4];
        }
        else if(s[i] == 'r'){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1];
            if(dp[i-1][2] != -1)
                dp[i][2] = a[i] + dp[i-1][2];
            if(dp[i-1][2] == -1)
                dp[i][3] = dp[i-1][3];
            else if(dp[i-1][3] == -1)
                dp[i][3] = dp[i-1][2];
            else
                dp[i][3] = min(dp[i-1][2], dp[i-1][3]);
            dp[i][4] = dp[i-1][4];
        }
        else if(s[i] == 'd'){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1];
            dp[i][2] = dp[i-1][2];
            if(dp[i-1][3] != -1)
                dp[i][3] = a[i] + dp[i-1][3];
            if(dp[i-1][3] == -1)
                dp[i][4] = dp[i-1][4];
            else if(dp[i-1][4] == -1)
                dp[i][4] = dp[i-1][3];
            else
                dp[i][4] = min(dp[i-1][3], dp[i-1][4]);
        }
        else{
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1];
            dp[i][2] = dp[i-1][2];
            dp[i][3] = dp[i-1][3];
            dp[i][4] = dp[i-1][4];
        }
    }
    ll ans = 1e18;
    for(i=0;i<4;++i){
        if(dp[n][i] == -1) continue;
        ans = min(ans, dp[n][i]);
    }
    printf("%lld\n", ans);
    return 0;
}