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
ll pt[61][61];

int main(){
    pt[0][0] = 1;
    for(int i=0;i<60;++i){
        pt[i][0] = 1;
        pt[i][i] = 1;
        for(int j=1;j<i;++j){
            pt[i][j] = pt[i-1][j-1] + pt[i-1][j];
        }
    }
    scanf("%d", &t);
    for(int cc=1;cc<=t;++cc){
        printf("Case #%d:\n", cc);
        scanf("%d", &n);
        int cnt = 0;
        int curr = 1;
        for(;;){
            cnt++;
            n -= curr;
            curr *= 2;
            if(n < curr) break;
        }
        bool rev = false;
        int outcnt = 0;
        for(int i=1;i<=cnt;++i){
            if(rev){
                for(int j=i;j>0;--j){
                    printf("%d %d\n", i, j);
                    outcnt++;
                }
            }
            else {
                for(int j=1;j<=i;++j){
                    printf("%d %d\n", i, j);
                    outcnt++;
                }
            }
            rev = !rev;
        }
        while(n){
            ++cnt;
            if(cnt - 1 <= n){
                n -= cnt-1;
                int lastplace = rev? cnt-1: 2;
                printf("%d %d\n", cnt, lastplace);
                outcnt++;
            }
            if(n){
                int lastplace = rev? cnt : 1;
                printf("%d %d\n", cnt, lastplace);
                n -= 1;
                outcnt++;
            }
        }
        debug(outcnt);
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