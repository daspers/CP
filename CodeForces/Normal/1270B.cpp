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
int a[200002];
int b[200002];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i=0;i<n;++i){
            int x;
            scanf("%d", &x);
            a[i] = x - i;
            b[i] = i + x;
        }
        // printArray(a, n);
        // printArray(b, n);
        int *mi = NULL;
        pii ans = {-1, -1};
        for(int i=0;i<n;++i){
            if(mi != NULL) {
                if(*mi < a[i]){
                    ans = {mi - a + 1, i+1};
                    break;
                }
                else if(*mi > a[i]){
                    mi = a+i;
                }
            }
            else {
                mi = a+i;
            }
        }
        if(ans.fi == -1){
            mi = NULL;
            for(int i=n-1;i>=0;--i){
                if(mi != NULL) {
                    if(*mi < b[i]){
                        ans = {i+1, mi - b + 1};
                        break;
                    }
                    else if(*mi > b[i]){
                        mi = b+i;
                    }
                }
                else {
                    mi = b+i;
                }
            }
        }
        if(ans.fi == -1){
            puts("NO");
        }
        else {
            puts("YES");
            printf("%d %d\n", ans.fi, ans.se);
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

/**
 * 
x = a[1] - 1
y = a[2] - 2
a[2] - a[1] - 2 + 1

x = a[1] + 1
y = a[2] + 2
x - y
a[1] + 1 - a[2] - 2

 * 
 */