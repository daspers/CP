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
int dp[30003];
pii a[100002];

int main(){
    memset(dp, 0, sizeof dp);
    scanf("%d", &n);
    for(i=0;i<n;++i)
        scanf("%d %d", &a[i].fi, &a[i].se);
    sort(a, a+n, [](const pii &a, const pii &b){
        return a.se < b.se;
    });
    int lst = 0;
    for(i=0;i<n;++i){
        while(lst < a[i].se){
            dp[lst+1] = dp[lst];
            lst++;
        }
        dp[a[i].se] = max(dp[a[i].se], dp[a[i].fi-1]+1);
    }
    printf("%d\n", dp[a[n-1].se]);
    return 0;
}