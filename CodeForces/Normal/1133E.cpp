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
int a[5002];
int dp[5002][5002];
int le[5002];
int par[5002];

void printArray(int *arr, int n){
    for(int i=0;i<n;++i){
        printf("%d ", arr[i]);
    }
    puts("");
}

int find_set(int v) {
    if (v == par[v])
        return v;
    return par[v] = find_set(par[v]);
}

int main(){
    scanf("%d %d", &n, &k);
    for(int i=1;i<=n;++i){
        scanf("%d", a+i);
    }
    a[0] = 0;
    sort(a+1, a+n+1);
    memset(dp, 0, sizeof dp);
    le[0] = 0;
    for(int i=1;i<=n;++i){
        le[i] = max((int)(lower_bound(a, a+n+1, a[i] - 5) - a - 1), 0);
    }
    // printArray(a+1, n);
    // printArray(le, n+1);
    for(int i=1;i<=k;++i){
        /* Optimize Form */
        for(int j=0;j<=n;++j)
            par[j] = j;
        stack<int> s;
        for(int j=0;j<=n;++j){
            dp[i-1][j] -= j;
        }
        for(int j=0;j<=n;++j){
            while(!s.empty() && dp[i-1][s.top()] <= dp[i-1][j]){
                par[s.top()] = j;
                s.pop();
            }
            s.push(j);
            if(j)
                dp[i][j] = dp[i][j-1];
            int idx = find_set(le[j]);
            dp[i][j] = max(dp[i][j], dp[i-1][idx] + j);
        }
        // printf("%d: \n", i);
        // printArray(dp[i]+1, n);
        /* Original Form
        for(int j=1;j<=n;++j){
            dp[i][j] = max(dp[i][j-1], query());
            for(int k=j-1;k>=0;--k){
                dp[i][j] = max(dp[i][j], dp[i-1][k] + j-k);
                if(a[j] - a[k] > 5) break;
            }
        }
        */
    }
    int ans = k;
    for(int i=0;i<=n;++i){
        ans = max(ans, dp[k][i]);
    }
    printf("%d\n", ans);
    return 0;
}