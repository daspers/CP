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

void printArray(const int *arr, int n);
void printArray(const vector<int> &arr);

const ll mod = 1e9+7;
const double PI = acos(-1);

int n,i,j,k,t;

int main(){
    ll n, p, d, w;
    scanf("%lld %lld %lld %lld", &n, &p, &w, &d);
    // cerr<<n<<" "<<p<<" "<<w<<" "<<d<<endl;
    ll x, y, g,lx,rx;
    g = __gcd(w, d);
    if(p % g)
        return puts("-1"), 0;
    for(y=0;y<w&&(p-d*y)%w;++y);
    if(y == w)
        return puts("-1"), 0;
    x = (p-d*y)/w;
    if( x < 0 || y < 0 || x+y > n)
        return puts("-1"), 0;
    printf("%lld %lld %lld\n", x, y, n-x-y);
    return 0;
}

/* Template Function */
void printArray(const int * a, int n){
    for(int i=0;i<n;++i){
        printf("%d ", a[i]);
    }
   puts("");
}

void printArray(const vector<int> &arr){
    for(int x : arr){
        printf("%d ", x);
    }
    puts("");
}