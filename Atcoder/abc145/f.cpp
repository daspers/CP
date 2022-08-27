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
int a[301];
int mi[300][300];
ll dp[300][300][301];
vector<pii> b[300][300];
vector<int> c[300][300], suf[300][300];
bool vis[300][300];

void fill_vector(int l, int r){
    if(vis[l][r]) return;
    vis[l][r] = true;
    if(l == r) return;
    int mini = mi[l][r];
    for(int i=l;i<=r;++i){
        if(a[i] > mini){
            int j;
            for(j=i+1;j<=r && a[j] > mini;++j);
            --j;
            b[l][r].pb({i, j});
            c[l][r].pb(j-i+1);
            i = j;
        }
    }
    suf[l][r] = c[l][r];
    for(int i=(int)c[l][r].size()-2;i>=0;--i){
        suf[l][r][i] += suf[l][r][i+1];
    }
}

ll solve(int l, int r, int k){
    ll &ans = dp[l][r][k];
    if(ans == -1){
        if(l == r){
            if(k) ans = 0;
            else ans = a[l];
        }
        else {
            if(k >= 1){
                ans = max(solve(l+1, r, k-1), solve(l, r-1, k-1));
            }
            fill_vector(l, r);
            for(int i=0;i<b[l][r].size();++i){
                // dafuq I gave up
            }
        }
    }
    return ans;
}

int main(){
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;++i){
        scanf("%d", a+i);
        mi[i][i] = a[i];
        for(int j=i-1;j>=0;--j){
            mi[j][i] = min(mi[j+1][i], a[j]);
        }
    }
    memset(vis, false, sizeof vis);
    memset(dp, -1, sizeof dp);
    ll ans = solve(0, n-1, k);
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