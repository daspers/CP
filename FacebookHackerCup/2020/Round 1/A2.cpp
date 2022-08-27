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
int k;
int a,b,c,d;
int l[1000005];
int h[1000005];
int w[1000005];
pii f[1000005];

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
            scanf("%d", w+i);
        }
        scanf("%d %d %d %d", &a, &b, &c, &d);
        for(int i=k;i<n;++i){
            w[i] = (1LL*a*w[i-2]%d + 1LL*b*w[i-1]%d + c) % d + 1;
        }
        for(int i=0;i<k;++i){
            scanf("%d", h+i);
        }
        scanf("%d %d %d %d", &a, &b, &c, &d);
        for(int i=k;i<n;++i){
            h[i] = (1LL*a*h[i-2]%d + 1LL*b*h[i-1]%d + c) % d + 1;
        }

        for(int i=0;i<n;++i){
            f[i] = {l[i], l[i]+w[i]};
        }

        ll ans = 1;
        ll cper = 0;
        set<pii> dep, bel;
        for(int i=0;i<n;++i){
            int lm = f[i].fi, rm = f[i].se, midx = i;
            while(true){
                set<pii>::iterator it1, it2;
                it1 = bel.lower_bound({lm, 0});
                if(it1 == bel.end() || f[it1->se].fi > rm ) {
                    it2 = dep.lower_bound({-rm, -n});
                    if(it2 == dep.end() || f[-it2->se].fi < lm) {
                        break;
                    }
                    else {
                        it1 = bel.lower_bound({f[-it2->se].se, -it2->se});
                        pii tmp1 = *it1;
                        bel.erase(it1);
                        pii tmp2 = *it2;
                        dep.erase(it2);
                        midx = min(tmp1.se, i);
                        lm = -max(tmp2.fi, -lm);
                        rm = max(tmp1.fi, rm);
                        cper = (cper - perimeter({f[tmp1.se].fi, 0}, {f[tmp1.se].se, h[tmp1.se]})) % mod;
                        debug(tmp1.se);
                    }
                }
                else {
                    it2 = dep.lower_bound({-f[it1->se].fi, -it1->se});
                    pii tmp1 = *it1;
                    bel.erase(it1);
                    pii tmp2 = *it2;
                    dep.erase(it2);
                    midx = min(tmp1.se, i);
                    lm = -max(tmp2.fi, -lm);
                    rm = max(tmp1.fi, rm);
                    cper = (cper - perimeter({f[tmp1.se].fi, 0}, {f[tmp1.se].se, h[tmp1.se]})) % mod;
                    debug(tmp1.se);
                }
            }
            cper = (cper + perimeter({lm, 0}, {rm, h[midx]})) % mod;
            debug5(i, midx, lm, rm, cper);
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