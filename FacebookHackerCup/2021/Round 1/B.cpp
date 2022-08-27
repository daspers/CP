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
int ans[55][55];
int m,a,b;

int main(){
    scanf("%d", &t);
    for(int cc=1;cc<=t;++cc) {
        printf("Case #%d: ", cc);
        scanf("%d %d %d %d", &n, &m, &a, &b);
        if (a < n+m-1 || b < n+m-1) {
            puts("Impossible");
            continue;
        }
        puts("Possible");
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) ans[i][j] = 1000;
        }
        for(int j=0;j<m;++j) ans[n-1][j] = 1;
        for(int i=0;i<n;++i) {
            ans[i][0] = 1;
            ans[i][m-1] = 1;
        }
        ans[0][0] = a - (n + m - 2);
        ans[0][m-1] = b - (n + m - 2);
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                printf("%d ", ans[i][j]);
            }
            puts("");
        }
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