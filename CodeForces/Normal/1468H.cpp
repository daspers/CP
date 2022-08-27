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
int a[200003];
int l[200003];
int r[200003];

int main(){
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d", &n, &k, &m);
        a[0] = a[n+1] = 0;
        for(int i=1;i<=n;++i){
            a[i] = 1;
        }
        for(int i=0;i<m;++i){
            int x = 0;
            scanf("%d", &x);
            a[x] = 0;
        }
        l[0] = 0;
        for(int i=1;i<=n;++i) {
            l[i] = l[i-1] + a[i];
        }
        r[n+1] = 0;
        for(int i=n;i>0;--i) {
            r[i] = r[i+1] + a[i];
        }
        if((n-m)%(k-1) != 0) {
            puts("NO");
            continue;
        }
        bool bisa = false;
        for(int i=1;i<=n;++i) {
            if(a[i] == 0){
                if ((l[i-1] >= k/2 && r[i+1] >= k/2)) {
                    bisa = true;
                    break;
                }
            }
        }
        puts(bisa? "YES":"NO");
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