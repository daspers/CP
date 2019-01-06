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
int a[22][22];
int dp[22][1<<22];

int solve(int idx, int state){
    int &ans= dp[idx][state];
    if(ans == -1){
        ans = 0;
        int now = 1;
        for(int i=0;i<n;++i, now<<=1){
            if(!a[idx][i] || (now & state)) continue;
            ans = (ans + solve(idx+1, state|now))%mod;
        }
    }
    return ans;
}

int main(){
    memset(dp, -1, sizeof dp);
    scanf("%d", &n);
    for(i=0;i<n;++i)
        for(j=0;j<n;++j)
            scanf("%d", a[i]+j);
    memset(dp[n], n, sizeof dp[n]);
    dp[n][(1<<n)-1] = 1;
    int ans = solve(0, 0);
    printf("%d\n", ans);
    return 0;
}