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
int a[3002];
ll dp[3002][3002];

ll solve(int st, int ed){
    ll &ans = dp[st][ed];
    if(ans == -1){
        if(st > ed)
            ans = 0;
        else{
            if(((ed-st)&1) == (n&1))
                ans = min(solve(st+1, ed) - a[st], solve(st, ed-1) - a[ed]);
            else
                ans = max(solve(st+1, ed) + a[st], solve(st, ed-1) + a[ed]);
        }
    }
    return ans;
}

int main(){
    memset(dp, -1, sizeof dp);
    scanf("%d", &n);
    for(i=0;i<n;++i)
        scanf("%d", a+i);
    // cout<<"masuk"<<endl;
    ll ans = solve(0, n-1);
    // cout<<"keluar"<<endl;
    printf("%lld\n", ans);
    return 0;
}