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

int n,k,t;
int m;
pii a, b;
// bool c[301][301];
// double ans[301][301];
long double d[200002];


int main(){
    d[1] = 0;
    for(int i=2;i<=200000;++i){
        d[i] = log2l(i) + d[i-1];
    }
    scanf("%d", &t);
    for(int cc=1;cc<=t;++cc){
        printf("Case #%d: ", cc);
        scanf("%d %d %d %d %d %d\n", &m, &n, &a.se, &a.fi, &b.se, &b.fi);
        long double ans = 0;
        priority_queue<long double> v;
        for(int x=a.se-2, y=b.fi;x>=0 && y<n;--x,++y){
            // debug2(x, y);
            v.push(-powl(2, d[x+y] - d[x] - d[y] - x - y));
            // ans += pow(2, d[x+y] - d[x] - d[y] - x - y);
        }
        for(int x=b.se, y=a.fi-2;x<m && y>=0;++x,--y){
            // debug2(x, y);
            v.push(-powl(2, d[x+y] - d[x] - d[y] - x - y));
            // ans += pow(2, d[x+y] - d[x] - d[y] - x - y);
        }
        while(v.size() > 1){
            long double tmp = v.top(); v.pop();
            tmp += v.top(); v.pop();
            v.push(tmp);
        }
        if(v.size() == 0) puts("0");
        else{
            printf("%.9Lf\n", -v.top());
            assert(-v.top() <= 1.0);
        }
        // if(n > 300 && m > 300){
        //     puts("0.0");
        //     continue;
        // }
        // for(int i=0;i<n;++i){
        //     for(int j=0;j<m;++j){
        //         c[i][j] = true;
        //         ans[i][j] = 0;
        //     }
        // }
        // for(int i=a.fi-1;i<b.fi;++i){
        //     for(int j=a.se-1;j<b.se;++j){
        //         c[i][j] = false;
        //     }
        // }
        // ans[0][0] = 1;
        // for(int i=0;i<n;++i){
        //     for(int j=0;j<m;++j){
        //         if(!c[i][j]) continue;
        //         if(i == n-1){
        //             ans[i][j+1] += ans[i][j];
        //         }
        //         else if(j == m-1) {
        //             ans[i+1][j] += ans[i][j];
        //         }
        //         else {
        //             ans[i+1][j] += ans[i][j] * 0.5;
        //             ans[i][j+1] += ans[i][j] * 0.5;
        //         }
        //     }
        // }
        // if(!c[n-1][m-1]) puts("0");
        // else printf("%.9lf\n", ans[n-1][m-1]);
        // for(int i=0;i<n;++i){
        //     for(int j=0;j<m;++j){
        //         printf("%.9lf ", ans[i][j]);
        //     }
        //     puts("");
        // }
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