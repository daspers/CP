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
pii a[104];
int b[204];
bool used[204];

bool is_possible(int l, int r, int val) {
    for(int i=l;i<=r;++i){
        if(b[i] == -1) continue;
        if(b[i] != val) return false;
    }
    return true;
}

int main(){
    scanf("%d", &n);
    memset(used, false, sizeof used);
    for(int i=0;i<n;++i){
        scanf("%d %d", &a[i].fi, &a[i].se);
        if(a[i].fi != -1) {
            if(used[a[i].fi]) {
                puts("No");
                return 0;
            }
            used[a[i].fi] = true;
        }
        if(a[i].se != -1) {
            if(used[a[i].se]) {
                puts("No");
                return 0;
            }
            used[a[i].se] = true;
        }
    }
    memset(b, -1, sizeof b);
    bool ans = true;
    for(int i=0;i<n;++i){
        if(a[i].fi != -1 && a[i].se != -1) {
            if(a[i].se <= a[i].fi) {
                puts("No");
                return 0;
            }
            int c = a[i].se-a[i].fi-1;
            for(int j=a[i].fi;j<=a[i].se;++j){
                if(b[j] == -1) b[j] = c;
                else if (b[j] != c) {
                    puts("No");
                    return 0;
                }
            }
        }
    }
    for(int i=0;i<n;++i){
        if(a[i].fi == -1 && a[i].se == -1) continue;
        else if(a[i].fi == -1) {
            int mac = a[i].se - 1 - 1;
            bool pos = false;
            for(int j=a[i].se;j>0;--j){
                int c = a[i].se - j - 1;
                if(!used[j] && is_possible(j, a[i].se, c)) pos = true;
            }
            if(!pos) {
                puts("No");
                return 0;
            }
        }
        else if(a[i].se == -1) {
            int mac = 2*n - a[i].fi - 1;
            bool pos = false;
            for(int j=a[i].fi;j<=2*n;++j){
                int c = j - a[i].fi - 1;
                if(!used[j] && is_possible(a[i].fi, j, c)) pos = true;
            }
            if(!pos) {
                puts("No");
                return 0;
            }
        }
    }
    puts(ans ? "Yes" : "No");
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