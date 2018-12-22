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

const ll mod = 998244353;
const double PI = acos(-1);

int n,i,j,k,t;
int m;
int dp[2002][2002];

int solve(int idx, int rem){
    int &ans = dp[idx][rem];
    if(ans == -1){
        if(idx == 0) ans = rem == 0;
        else{
            ans = solve(idx - 1, rem);
            if(rem){
                ans += 1LL*(m-1) * solve(idx - 1, rem - 1) % mod;
                ans %= mod;
            }
        }
    }
    return ans;
}

int main(){
    memset(dp, -1, sizeof dp);
    scanf("%d %d %d", &n, &m, &k);
    if(m == 1 && k > 0)
        return puts("0") & 0;
    int ans = solve(n-1, k);
    ans = 1LL*m*ans % mod;
    printf("%d\n", ans);
	return 0;
}