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

int n,i,j,k,t,m;
char s[200];
int g[30][30];

int main(){
    scanf("%d", &t);
    for(int cc=1;cc<=t;++cc) {
        printf("Case #%d: ", cc);
        scanf("%s", s);
        n = strlen(s);
        scanf("%d", &m);
        memset(g, -1, sizeof g);
        for(int i=0;i<m;++i) {
            char a[4];
            scanf("%s", a);
            g[a[0]-'A'][a[1]-'A'] = 1;
        }
        for(int i=0;i<26;++i) g[i][i] = 0;
        for(int i=0;i<26;++i) {
            for(int j=0;j<26;++j) {
                for(int k=0;k<26;++k) {
                    if (g[i][k] == -1 || g[k][j] == -1) continue;
                    if (g[i][j] == -1) g[i][j] = g[i][k] + g[k][j];
                    else if (g[i][j] > g[i][k] + g[k][j]) g[i][j] = g[i][k] + g[k][j];
                } 
            }
        }
        int ans = n * 27;
        for(int c=0;c<26;++c) {
            int sum = 0;
            for(int i=0;i<n;++i) {
                if (g[s[i]-'A'][c] == -1) {
                    sum = -1;
                    break;
                } else {
                    sum += g[s[i]-'A'][c];
                }
            }
            if (sum >= 0) {
                ans = min(ans, sum);
            }
        }
        printf("%d\n", ans == n*27 ? -1 : ans);
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