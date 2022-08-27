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
ll a[100005];
ll b[100005];
ll c[100005];

int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;++i){
        scanf("%lld", a+i);
    }
    b[0] = b[n+1] = 0;
    c[0] = c[n+1] = 0;
    for(int i=1;i<=n;++i){
        b[i] = b[i-1] ^ a[i];
    }
    for(int i=n;i>=1;--i){
        c[i] = c[i+1] ^ a[i];
    }
    ll ans = 0;
    for(int i=1;i<=n;++i){
        ll xo = b[i-1] ^ c[i+1];
        ll p2 = 1;
        while(p2 <= a[i]) p2 <<= 1;
        ll curr = (p2 - 1) ^ (xo & (p2-1));
        ll sub = curr;
        if (sub > a[i]) {
            ll sel = sub - a[i];
            if ((sub & sel) < sel) {
                ll pp2 = 1;
                while(pp2 <= sel) pp2 <<= 1;
                while(!(pp2 & sub)) pp2 <<= 1;
                sub = sub - pp2;
            }
            else {
                sub -= (sel) & curr;
            }
        }
        // debug3(a[i], xo, sub ^ xo);
        // debug3(curr, sub, a[i]);
        ans = max(ans, sub ^ xo);
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