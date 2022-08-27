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
int a,b,m;
int c[200002];

int main(){
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d %d", &n, &m, &a, &b);
        if (b < a) {
            b = n - b + 1;
            a = n - a + 1;
        }
        int sel = b - a;
        for(int i=0;i<m;++i) {
            scanf("%d", c+i);
        }
        sort(c, c+m, greater<int>());
        // if (sel <= m) {
        //     sort(c, c+sel, greater<int>());
        // } else {
        //     sort(c, c+m, greater<int>());
        // }
        int ans = 0;
        // printArray(c, m);
        for(int i=0;i<m;++i) {
            // printf("> %d %d\n", c[i]+ans+1, b-1);
            // if (ans == sel - 1) {
            //     if (c[i] <= 1) {
            //         ans++;
            //     }
            // } else 
            if (ans < sel - 1) {
                if (c[i]+ans+1 < b) {
                    ans++;
                }
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