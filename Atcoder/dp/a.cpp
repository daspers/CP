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
int h[100002];
int dp[100002];

int main(){
    scanf("%d", &n);
    for(i=0;i<n;++i)
        scanf("%d", h+i);
    dp[0] = 0;
    for(i=1;i<n;++i){
        dp[i] = abs(h[i] - h[i-1]) + dp[i-1];
        if(i>1)
            dp[i] = min(dp[i], dp[i-2] + abs(h[i] - h[i-2]));
    }
    printf("%d\n", dp[n-1]);
	return 0;
}
