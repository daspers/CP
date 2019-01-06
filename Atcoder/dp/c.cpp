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
int a[100002][3];
int dp[100002][3];


int main(){
    scanf("%d", &n);
    for(i=1;i<=n;++i)
        scanf("%d %d %d", a[i], a[i]+1, a[i]+2);
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for(i=1;i<=n;++i){
        dp[i][0] = a[i][0] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = a[i][1] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = a[i][2] + max(dp[i-1][0], dp[i-1][1]);
    }
    printf("%d\n", max(dp[n][0], max(dp[n][1], dp[n][2])));
	return 0;
}