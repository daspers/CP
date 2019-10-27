#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-9
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define debug2(a, b) cerr<<#a<<"="<<(a)<<" ";debug(b)
#define debug3(a, b, c) cerr<<#a<<"="<<(a)<<" ";debug2(b, c)
#define debug4(a, b, c, d) cerr<<#a<<"="<<(a)<<" ";debug3(b, c, d)
#define debug5(a, b, c, d, e) cerr<<#a<<"="<<(a)<<" ";debug4(b, c, d, e)
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<class T>
void printArray(const T * a, int n, ostream& out = cerr);
template<class T>
void printArray(const vector<T> &arr, ostream& out = cerr);

const ll mod = 1e9+7;
const double PI = acos(-1);

int n,i,j,k,t;
int g1, g2, g3;
char s[100010];
int dp[100010][51];

int main(){
    scanf("%d %d %d %d %d", &n, &k, &g1, &g2, &g3);
    scanf("%s", s+1);
    int cnt  = count_if(s+1, s+1+n, [](char c){return c == '.';});
    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;
    dp[1][0] = 0;
    for(int i=2;i<=n;++i){
        for(int j=0;j<=50;++j){
            dp[i][j] = dp[i-1][j];
        }
        if(s[i] == '.' && s[i-1] == '.'){
            for(int j=0;j<=50;++j){
                if(dp[i-2][j] == -1) continue;
                dp[i][j] = max(dp[i][j], dp[i-2][j] + 1);
            }
        }
        if(i > 2 && s[i] == '.' && s[i-1] == '#' && s[i-2] == '.'){
            for(int j=1;j<=50;++j){
                if(dp[i-3][j-1] == -1) continue;
                dp[i][j] = max(dp[i][j], dp[i-3][j-1]);
            }
        }
    }
    vector<pii> cmd;
    if(g1 > g2) {
        cmd.pb({g1-g2, 1});
    }
    if(2*g1 > g2) {
        cmd.pb({2*g1-g2, 3});
    }
    if(g1 > g3) {
        cmd.pb({g1-g3, 2});
    }
    if(2*g1 > g3) {
        cmd.pb({2*g1-g3, 4});
    }
    sort(cmd.begin(), cmd.end(), greater<pii>());
    ll ans = 0;
    for(int i=0;i<=50;++i){
        if(dp[n][i] == -1) continue;
        int c2=dp[n][i], c3=i;
        int rem = cnt - 2*c3 - 2*c2;
        int curr = k;
        int mi = min(rem, curr);
        ll tmp = 1LL * mi * g1;
        curr -= mi;

        for(pii x : cmd){
            switch (x.se){
            case 1:
                mi = min(c2, curr);
                curr -= mi;
                c2 -= mi;
                tmp += 1LL*mi*g1;
                break;
            case 2:
                mi = min(c3, curr);
                curr -= mi;
                c3 -= mi;
                tmp += 1LL*mi*g1;
                break;
            case 3:
                mi = min(c2, curr/2);
                curr -= 2*mi;
                c2 -= mi;
                tmp += 2LL*mi*g1;
                break;
            case 4:
                mi = min(c3, curr/2);
                curr -= 2*mi;
                c3 -= mi;
                tmp += 2LL*mi*g1;
                break;
            default:
                break;
            }
        }

        tmp += 1LL*c2*g2;
        tmp += 1LL*c3*g3;
        // debug3(i, dp[n][i], tmp);
        ans = max(ans, tmp);
    }

    printf("%lld\n", ans);
    return 0;
}

/* Template Function */
template<class T>
void printArray(const T * a, int n, ostream& out){
    for(int i=0;i<n;++i){
        out<<a[i]<<" ";
    }
    out<<endl;
}

template<class T>
void printArray(const vector<T> &arr, ostream& out){
    for(const T& x : arr){
        out<<x<<" ";
    }
    out<<endl;
}