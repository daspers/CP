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

int i,j,k,t;
int m;
int p[100];
ll n[100];
ll ans;
// map<pair<int, pll>, ll> dp;

void bf(int id, ll pr, ll s) {
    if (pr == s) {
        ans = max(ans, pr);
        return;
    } 
    if (pr > s || id >= m) {
        return;
    }
    int ma = min(n[id], ll(log(s)/log(p[id])));
    // printf("%d %d %d %d %d\n", id, p[id], ma, pr, s);
    ll pw = 1;
    ll sm = 0;
    for (int i=0;i<=ma;++i) {
        if (pr * pw > s - sm) {
            break;
        }
        bf(id+1, pr*pw, s-sm);
        pw *= p[id];
        sm += p[id];
    }
}

int main(){
    scanf("%d", &t);
    for(int cc=1;cc<=t;++cc){
        scanf("%d", &m);
        ll sum = 0;
        for(int i=0;i<m;++i) {
            scanf("%d %lld", p+i, n+i);
            sum += p[i] * n[i];
        }
        ans = 0;
        bf(0, 1, sum);
        // dp.clear();
        printf("Case #%d: %lld\n", cc, ans);
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