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
int q;
int a[9][100002];
int b[9][100002];


int main(){
    scanf("%d %d", &n, &q);
    for(int i=1;i<=n;++i){
        scanf("%d", a[0] + i);
    }
    for(int i=1;i<=n;++i)
        b[0][i] = 1;
    for(int i=1;i<=k;++i){
        b[i][1] =1;
        for(int j=2;j<=n;++j){
            b[i][j] = b[i][j-1] + b[i-1][j];
        }
    }
    for(int i=1;i<9;++i){
        reverse(b[i], b[i]+n+2);
    }
    for(int i=1;i<=k;++i){
        for(int j=0;j<n;++j){
            a[i][j] = a[0][j] * b[i][j] % mod;
        }
    }

    while(q--){

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