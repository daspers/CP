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
int a[200002], b[200002], c[200002], d[200002];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i=0;i<n;++i){
            scanf("%d", a+i);
            d[i] = 0;
        }
        scanf("%d", &m);
        for(int i=0;i<m;++i){
            scanf("%d %d", b+i, c+i);
            --c[i];
            c[i] = min(c[i], n-1);
            d[c[i]] = max(d[c[i]], b[i]);
        }
        for(int i=n-2;i>=0;--i){
            d[i] = max(d[i], d[i+1]);
        }
        // printArray(d, n);
        int ans = 0;
        for(int i=0;i<n;++i){
            ans++;
            int j=i;
            int curr = a[i];
            if(curr > d[0]){
                ans = -1;
                break;
            }
            while(j+1<n && max(a[j+1], curr) <= d[j-i+1]){
                ++j;
                curr = max(a[j], curr);
            }
            // debug2(i, j);
            i = j;
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