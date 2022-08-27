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
ll a, b;

ll hitung(ll x){
    a -= 2*x;
    b -= x;
    ll y = min(b/2, a);
    if(y == 0) return 0;
    return x + y;
}

int main(){
    scanf("%lld %lld", &a, &b);
    ll ma = (a + b)/3;
    ll ma1 = a - ma;
    ll ma2 = b - ma;
    ll l1 = 1, r1 = ma1;
    ll l2 = 1, r2 = ma2;
    while(l1+2 < r1){
        ll mid1 = (2*l1 + r1)/2;
        ll mid2 = (l1 + 2*r1)/2;
        if(hitung(mid1) > hitung(mid2)){
            r1 = mid2;
        }
        else{
            l1 = mid1;
        }
    }
    ll ans = 0;
    for(ll i = l1;i<=r1;++i){
        ans = max(ans, hitung(i));
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