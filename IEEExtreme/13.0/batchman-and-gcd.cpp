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
int a[100002];
bool isp[100002];
int cnt[100002];
ll dp[100002];
bool vis[100002];
vector<int> v;
set<int> adj[100002];

int main(){
    memset(cnt, 0, sizeof cnt);
    memset(isp, true, sizeof isp);
    isp[0] = false;
    for(int i=2;i<=100000;++i){
        if(isp[i]){
            if(i > 100000 / i) continue;
            for(int j=i*i;j<=100000;j+=i){
                isp[j] = false;
            }
        }
    }
    scanf("%d %d", &n, &k);
    int tot = 0;
    for(int i=0;i<n;++i){
        scanf("%d", a+i);
        v.pb(a[i]);
        tot = __gcd(tot, a[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int x : v){
        int sq = sqrt(x);
        for(int j=1;j<=sq;++j){
            if(x % j == 0){
                cnt[j]++;
                if(x/j != j) cnt[x/j]++;
            }
        }
    }
    for(int i=100000;i>0;--i){
        dp[i] = cnt[i] ;
        if(k > 1 ) dp[i] += 1LL*cnt[i]*(cnt[i]-1)/2;
        for(int j=2;i*j <= 100000;++j){
            dp[i] -= dp[i*j];
        }
    }
    int ans = 0;
    for(int i=1;i<=100000;++i){
        ans += dp[i] > 0;
    }
    // printArray(dp, 20);
    printf("%d\n", ans);
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