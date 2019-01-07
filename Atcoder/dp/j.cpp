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
double dp[301][301][301];
bool vis[301][301][301];
int a[304];
int cnt[4];

double solve(int c3, int c2, int c1){
    double &ans = dp[c3][c2][c1];
    if(!vis[c3][c2][c1]){
        vis[c3][c2][c1] = true;
        int sum = c3+c2+c1;
        ans = 1.0/sum;
        if(sum){
            if(c3)
                ans += 1.0*c3/sum *(solve(c3-1, c2+1, c1));
            if(c2)
                ans += 1.0*c2/sum *(solve(c3, c2-1, c1+1));
            if(c1)
                ans += 1.0*c1/sum *(solve(c3, c2, c1-1));
        }
    }
    return ans;
}

int main(){
    memset(cnt, 0, sizeof cnt);
    memset(vis, false, sizeof vis);
    scanf("%d", &n);
    for(i=0;i<n;++i){
        scanf("%d", a+i);
        cnt[a[i]]++;
    }
    vis[0][0][0] = true;
    dp[0][0][0] = 0;
    printf("%.9lf\n", n*solve(cnt[3], cnt[2], cnt[1]));
    return 0;
}