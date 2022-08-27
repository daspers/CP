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
int a[101][101];

int main(){
    scanf("%d", &t);
    for(int cc=1;cc<=t;++cc){
        scanf("%d", &n);
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                scanf("%d", a[i]+j);
            }
        }
        int k=0,r=0,c=0;
        for(int i=0;i<n;++i){
            k += a[i][i];
        }
        for(int i=0;i<n;++i){
            vector<int> v;
            for(int j=0;j<n;++j){
                v.pb(a[i][j]);
            }
            sort(v.begin(), v.end());
            v.erase(unique(v.begin(), v.end()), v.end());
            r += v.size() != n;
        }
        for(int i=0;i<n;++i){
            vector<int> v;
            for(int j=0;j<n;++j){
                v.pb(a[j][i]);
            }
            sort(v.begin(), v.end());
            v.erase(unique(v.begin(), v.end()), v.end());
            c += v.size() != n;
        }
        printf("Case #%d: %d %d %d\n", cc, k, r, c);
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