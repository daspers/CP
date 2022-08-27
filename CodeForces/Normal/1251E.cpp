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
int s;
pii a[200002];
ll dp[200002];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        ll ans = 0;
        for(int i=0;i<n;++i){
            scanf("%d %d", &a[i].fi, &a[i].se);
            ans += a[i].se;
        }
        sort(a, a+n);
        dp[0] = 0;
        int llb = 0;
        for(int i=n-1;i>=0;--i){
            dp[n-i] = a[i].se + dp[n-i-1];
            for(int j=n-i-1;j>llb;--j){
                dp[j] = min(dp[j], dp[j-1] + a[i].se);
            }
            llb = max(llb, a[i].fi-i);
        }
        for(int i=llb;i<=n;++i){
            if(dp[i] == -1) continue;
            ans = min(ans, dp[i]);
        }
        printf("%lld\n", ans);
    }
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