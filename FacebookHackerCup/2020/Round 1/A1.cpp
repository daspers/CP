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

template<class T> void printArray(const T * a, int n, ostream& out = cerr);
template<class T> void printArray(const vector<T> &arr, ostream& out = cerr);
ostream& operator<<(ostream &os, const pii &a){
    return os << "("<<a.fi<<","<<a.se<<")";
}

const ll mod = 1e9+7;
const double PI = acos(-1);

int n,t;
int k, w;
int a,b,c,d;
int l[1000005];
int h[1000005];

int perimeter(const pii &a, const pii &b){
    return ((2LL * abs(a.fi - b.fi) + 2LL * abs(a.se - b.se))) % mod;
}

bool intersect(const pii &a, const pii &b, const pii &c, const pii &d){
    // return !(c.fi > b.fi || d.fi < a.fi || c.se > b.se || d.se < a.se);
    return c.fi <= b.fi;
}

int main(){
    scanf("%d", &t);
    for(int cc=1;cc<=t;++cc){
        printf("Case #%d: ", cc);
        scanf("%d %d %d", &n, &k, &w);
        for(int i=0;i<k;++i){
            scanf("%d", l+i);
        }
        scanf("%d %d %d %d", &a, &b, &c, &d);
        for(int i=k;i<n;++i){
            l[i] = (1LL*a*l[i-2]%d + 1LL*b*l[i-1]%d + c) % d + 1;
        }
        for(int i=0;i<k;++i){
            scanf("%d", h+i);
        }
        scanf("%d %d %d %d", &a, &b, &c, &d);
        for(int i=k;i<n;++i){
            h[i] = (1LL*a*h[i-2]%d + 1LL*b*h[i-1]%d + c) % d + 1;
        }

        ll ans = 1;
        ll cper = 0;
        pii lbl = {0, 0}, lur={0, 0};
        debug(w);
        printArray(l, n);
        printArray(h, n);
        for (int i=0;i<n;++i){
            pii cbl = {l[i], 0};
            pii cur = {l[i]+w, h[i]};
            if (intersect(lbl, lur, cbl, cur)) {
                cper = (cper - perimeter(lbl, lur)) % mod;
                lbl = {
                    min(lbl.fi, cbl.fi),
                    min(lbl.se, cbl.se)
                };
                lur = {
                    max(lur.fi, cur.fi),
                    max(lur.se, cur.se)
                };
            }
            else {
                lbl = cbl;
                lur = cur;
            }
            cper = (cper + perimeter(lbl, lur)) % mod;
            debug2(i, cper);
            ans = ans * cper % mod;
        }
        if(ans < 0) ans += mod;
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