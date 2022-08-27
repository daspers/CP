#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
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
char s[105][105];
int a[1<<15][8][8];
int b[1<<15][8][8];

const int modu1=mod;
const int modu2=mod+2;
pii hashgrid(int *a, int n){
    int val1 = 0;
    int val2 = 0;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            val1 = (3*val1 + *(a + i*8 + j) + 1) % modu1;
            val2 = (3*val2 + *(a + i*8 + j) + 1) % modu2;
        }
    }
    return {val1, val2};
}

void print(int *a, int n){
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            printf("%d ", *(a + i*8 + j));
        }
        puts("");
    }
}

int main(){
    scanf("%d", &t);
    for(int cc=1;cc<=t;++cc){
        scanf("%d", &n);
        for(int i=0;i<n;++i){
            scanf("%s", s[i]);
        }
        if(n > 8) exit(0);
        int total = 1<<(2*n-1);
        memset(b, 0, sizeof b);
        map<pii, int> ma, mb;
        for(int i=0;i<total;++i){
            for(int j=0;j<n;++j){
                for(int k=0;k<n;++k){
                    a[i][j][k] = s[j][k] != '#';
                }
            }
            for(int j=0;j<2*n-1;++j){
                if(i & (1<<j)){
                    for(int x=0;x<n;++x){
                        int ya = -(j-n+1-x);
                        int yb = j-x;
                        if(ya >= 0 && ya < n){
                            a[i][x][ya] ^= 1;
                        }
                        if(yb >= 0 && yb < n){
                            b[i][x][yb] ^= 1;
                        }
                    }
                }
            }
            pii ha = hashgrid((int *)a[i], n);
            pii hb = hashgrid((int *)b[i], n);
            // debug5(i, ha.fi, ha.se, hb.fi, hb.se);
            // print((int *)a[i], n);
            // print((int *)b[i], n);
            if(ma.count(ha)){
                ma[ha] = min(ma[ha], __builtin_popcount(i));
            }
            else {
                ma[ha] = __builtin_popcount(i);
            }
            if(mb.count(hb)){
                mb[hb] = min(mb[hb], __builtin_popcount(i));
            }
            else {
                mb[hb] = __builtin_popcount(i);
            }
        }
        int ans = n*n;
        for(const pair<pii, int> & a : ma){
            if(mb.count(a.fi)){
                ans = min(ans, a.se + mb[a.fi]);
            }
        }
        printf("Case #%d: %d\n", cc, ans);
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