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
#define debug6(a, b, c, d, e, f) cerr<<#a<<"="<<(a)<<" ";debug5(b, c, d, e, f)
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
int arr[1000002], r[1000002];
ll sum[1000002], b[1000002];

int main(){
    scanf("%d", &t);
    for(int cc=1;cc<=t;++cc) {
        printf("Case #%d: ", cc);
        scanf("%d", &n);
        scanf("%s", s+1);
        arr[0] = 0;
        char last = 0;
        for(int i=1;i<=n;++i) {
            arr[i] = arr[i-1];
            if (s[i] == 'X' || s[i] == 'O') {
                if (last && last != s[i]) {
                    arr[i] += 1;
                }
                last = s[i];
            }
        }
        sum[n+1] = 0;
        for(int i=n;i>0;--i) {
            sum[i] = (sum[i+1] + arr[i]) % mod;
        }
        r[n] = n;
        for(int i=n-1;i>0;--i) {
            if (s[i] == 'X' || s[i] == 'O') {
                r[i] = i;
            } else {
                r[i] = r[i+1];
            }
        }
        // printf("\n");
        // printArray(s+1, n);
        // printArray(arr+1, n);
        // printArray(sum+1, n);
        ll ans = 0;
        b[n] = 0;
        for(int i=n;i>0;--i) {
            if (s[i] == 'F') {
                b[i] = b[r[i]];
            } else {
                b[i] = (sum[i] - ((n+1-i) * arr[i]) % mod) % mod;
            }
            ans = (ans+b[i]) % mod;
        }
        ans = ans % mod;
        if (ans < 0 ) {
            ans += mod;
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