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
char s[1005];
int dp[1005][256];
int a, b;

int hitung(int prev, char p, char c) {
    if (prev == -1) {
        return -1;
    }
    if (p == c) {
        return prev;
    }
    if (p == 'C') {
        return prev + a;
    } else {
        return prev + b;
    }
} 

int mina(int a, int b) {
    return a==-1? b : b == -1 ? a : min(a, b);
}

int main(){
    scanf("%d", &t);
    for(int cc=1;cc<=t;++cc) {
        printf("Case #%d: ", cc);
        scanf("%d %d %s", &a, &b, s);
        n = strlen(s);
        memset(dp, -1, sizeof dp);
        // memset(dp[0], 0, sizeof dp[0]);
        if (s[0] == '?') {
            dp[0]['C'] = dp[0]['J'] = 0;
        } else if (s[0] == 'J') {
            dp[0]['J'] = 0;
        } else {
            dp[0]['C'] = 0;
        }
        // printf("\n");
        // printf("%d %c: %d %d\n", 0, s[0], dp[0]['C'], dp[0]['J']);
        for(int i=1;i<n;++i) {
            if (s[i] == '?') {
                dp[i]['C'] = mina(hitung(dp[i-1]['C'], 'C', 'C'), hitung(dp[i-1]['J'], 'J', 'C'));
                dp[i]['J'] = mina(hitung(dp[i-1]['C'], 'C', 'J'), hitung(dp[i-1]['J'], 'J', 'J'));
            } else {
                dp[i][s[i]] = mina(hitung(dp[i-1]['C'], 'C', s[i]), hitung(dp[i-1]['J'], 'J', s[i]));
            }
            // printf("%d %c: %d %d\n", i, s[i], dp[i]['C'], dp[i]['J']);
        }
        printf("%d\n", mina(dp[n-1]['C'], dp[n-1]['J']));
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