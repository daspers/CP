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
int a[102];
int dp[100003][2];

int solve(int num, int p){
    int &ans = dp[num][p];
    if(ans == -1){
        ans = p^1;
        for(int i=0;i<n;++i){
            if(num < a[i]) break;
            int tmp = solve(num - a[i], p^1);
            if(tmp == p)
                ans = tmp;
        }
        // cout<<num<<" "<<p<<" "<<ans<<endl;
    }
    return ans;
}

int main(){
    memset(dp, -1, sizeof dp);
    scanf("%d %d", &n, &k);
    for(i=0;i<n;++i)
        scanf("%d", a+i);
    sort(a, a+n);
    int ans = solve(k, 0);
    puts(ans?"Second":"First");
    return 0;
}