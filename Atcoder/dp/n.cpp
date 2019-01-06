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
int a[500];
ll psum[500];
ll dp[402][402];

ostream& operator<<(std::ostream& stream, const pair<ll, pii>& ot){
    stream << ot.fi <<" "<<ot.se.fi<<" "<<ot.se.se;
    return stream;
}

ll solve(int l, int r){
    ll &ans = dp[l][r];
    if(ans == -1){
        if(l == r)
            ans = 0;
        else{
            ans = psum[r] - psum[l-1];
            ll mini = solve(l+1, r);
            for(int i=l+1;i<r;++i)
                mini = min(mini, solve(l, i) + solve(i+1, r));
            ans += mini;
        }
    }
    return ans;
}

int main(){
    memset(dp, -1, sizeof dp);
    scanf("%d", &n);
    psum[0] = 0;
    for(i=1;i<=n;++i){
        scanf("%d", a+i);
        psum[i] = a[i] + psum[i-1];
    }
    ll ans = solve(1, n);
    printf("%lld\n", ans);
    return 0;
}