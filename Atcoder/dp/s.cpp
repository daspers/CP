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
int d;
char s[10005];
int dp[10005][2][100];

int solve(int idx, int ub, int val){
    int &ans = dp[idx][ub][val];
    if(ans == -1){
        ans = 0;
        if(ub){
            int ma = s[idx]-'0';
            ans = solve(idx-1, 1, (val+ma)%d);
            for(i=0;i<ma;++i)
                ans = (ans + solve(idx-1, 0, (val+i)%d)) % mod;
        }
        else{
            for(int i=0;i<10;++i)
                ans = (ans + solve(idx-1, 0, (val+i)%d)) % mod;
        }
    }
    return ans;
}

int main(){
    memset(dp, -1, sizeof dp);
    scanf("%s", s+1);
    n = strlen(s+1);
    scanf("%d", &d);
    reverse(s+1, s+n+1);
    memset(dp[0], 0, sizeof dp[0]);
    dp[0][1][0] = dp[0][0][0] = 1;
    int ans = (mod + solve(n, 1, 0) - 1)%mod;
    printf("%d\n", ans);
    return 0;
}