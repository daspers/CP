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
int m;

int main(){
    scanf("%d", &t);
    for(int cc=1;cc<=t;++cc) {
        printf("Case #%d: ", cc);
        scanf("%d %d %d", &n, &m, &k); --k;
        vector<vector<char>> s(n, vector<char>(m+2, 0));
        vector<vector<int>> pref(n, vector<int>(m+2, 0));
        vector<vector<int>> suff(n, vector<int>(m+2, 0));
        for(int i=0;i<n;++i) {
            scanf("%s", &s[i][0]);
        }
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                if (j) pref[j][i] = pref[j-1][i];
                pref[j][i] += s[j][i] == 'X';
            }
        }
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                if (j<n-1) suff[j][i] = suff[j+1][i];
                suff[j][i] += s[j][i] == 'X';
            }
        }
        int ans = 0;
        for(int i=0;i<m;++i) ans += s[k][i] == 'X';
        // up
        for(int i=1;i<n-k;++i) {
            int tmp = i;
            for(int j=0;j<m;++j) {
                tmp += (s[i+k][j] == 'X' || pref[i+k][j] >= k+1);
            }
            // int tmp2 = i+1;
            // for(int j=0;j<m;++j) {
            //     tmp += (s[i+k][j] == 'X' || pref[i+k][j] >= k+1 || suff);
            // }
            ans = min(ans, tmp);
        }
        for(int i=1;i<=k;++i) {
            int tmp = i;
            for(int j=0;j<m;++j) {
                tmp += (s[k-i][j] == 'X' || suff[k-i][j] >= n-k );
            }
            ans = min(ans, tmp);
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