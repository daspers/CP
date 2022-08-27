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
pair<pii, pii> a[100002];
pii b[100002];

int main(){
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        map<pii, int> m;
        for(int i=0;i<n;++i) {
            scanf("%d %d %d %d", &a[i].fi.fi, &a[i].fi.se, &a[i].se.fi, &a[i].se.se);
            int sx = a[i].se.fi - a[i].fi.fi;
            int sy = a[i].se.se - a[i].fi.se;
            int gcd = __gcd(abs(sx), abs(sy));
            sx /= gcd;
            sy /= gcd;
            b[i] = {sx, sy};
            m[b[i]]++;
        }
        ll ans = 0;
        for(int i=0;i<n;++i) {
            pii r = {-b[i].fi, -b[i].se};
            if (m.count(r)) {
                ans += m[r];
            }
        }
        printf("%lld\n", ans / 2);
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