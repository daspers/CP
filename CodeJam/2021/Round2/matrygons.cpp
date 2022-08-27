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
int cnt[1000002];

int calc(int n) {
    int &ans = cnt[n];
    if (ans == 0) {
        ans = n > 2 ? 2 : 1;
        for(int i=2;i<=sqrt(n);++i) {
            if (n % i == 0) {
                int j = n/i;
                ans = max(ans, 1 + calc(n-i));
                ans = max(ans, 1 + calc(n-j));
            }
        }
        printf("calc(%d)=%d\n", n, ans);
    }
    return ans;
}

int lol(int n) {
    int &ans = cnt[n];
    if (ans == 0) {
        ans = 1;
        if (n > 2) {
            int tmp = n-1;
            int sq = tmp >= 4 ? sqrt(tmp): tmp;
            for (int i=2;i<=sq;++i) {
                if (tmp % i == 0) {
                    ans = max(ans, 1 + lol(tmp / i));
                }
            }
        }
    }
    // printf("calc(%d)=%d\n", n, ans);
    return ans;
}

int main(){
    scanf("%d", &t);
    for(int cc=1;cc<=t;++cc) {
        printf("Case #%d: ", cc);
        scanf("%d", &n);
        int sq = sqrt(n);
        int ans = 1;
        for(int i=3;i<=sq;++i) {
            if (n % i == 0) {
                ans = max(ans, lol(n/i));
                // break;
            }
        }
        printf("%d\n", ans);
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