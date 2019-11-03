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
char s[1000002];
// ll ans[1000002];

int msb(ull val) {
    return 63 - __builtin_clzll(val);
}

struct superdecimal{
    ull sig;
    int exp;

    superdecimal(): sig(0), exp(0) {};
    superdecimal(ull a): sig(a), exp(0) {
        if(msb(sig) == 63){
            sig >>= 1;
            exp++;
        }
    };
    superdecimal(ull a, int b): sig(a), exp(b) {
        if(msb(sig) == 63){
            sig >>= 1;
            exp++;
        }
    };
    long double to_ldouble(){
        return 1.0L * sig *powl(2, exp);
    }
};

superdecimal operator+(const superdecimal &a, const superdecimal &b){
    if(a.sig == 0) return b;
    if(b.sig == 0) return a;
    if(a.exp < b.exp) {
        return b + a;
    }
    int diff = a.exp - b.exp;
    superdecimal c(a);
    if(62 - diff - msb(c.sig) >= 0){
        int mi = min(62 - diff - msb(c.sig) , diff);
        c.sig <<= mi;
        c.exp -= mi;
        diff -= mi;
    }
    c.sig += (b.sig >> diff);
    if(msb(c.sig) == 63){
        c.sig >>= 1;
        c.exp ++;
    }
    return c;
}

int main(){
    scanf("%s", s);
    n = strlen(s);
    int tq = count_if(s, s+n, [](char c){return c == '?';});
    long double ans = 0;
    int cq = 0, ch = 0;
    superdecimal wtf;
    for(int i=n-1;i>=0;--i){
        if(s[i] == 'H'){
            // ans += powl(2, cq -tq);
            wtf = wtf + superdecimal(1, cq);
            ch++;
        }
        else if(s[i] == '?') {
            // ans = (2 * ch + cq + 1) * powl(2, cq - tq) + 2 * ans;
            wtf = wtf + wtf;
            wtf = wtf + superdecimal(2 * ch + cq + 1, cq);
            cq++;
        }
        else {
            // ans += (2 * ch + cq) * powl(2, cq - tq);
            wtf = wtf + superdecimal(2 * ch + cq, cq);
        }
    }
    // printf("%.12Lf\n", ans);
    wtf.exp -= tq;
    printf("%.12Lf\n", wtf.to_ldouble());
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