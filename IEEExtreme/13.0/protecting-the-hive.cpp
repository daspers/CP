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
int m, q;
int a[101][101];
int b[101][101];
int par[10005];
int per[10005];
int dx[] = {i-1, i-1, i+1, i+1, i, i};
int dy[2][6] = {
    {j, j-1, j, j-1, j-1, j+1},
    {j, j+1, j, j+1, j-1, j+1}
};

int find_set(int v){
    if(par[v] == v) return v;
    return par[v] = find_set(par[v]);
}

void union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        // cerr<<"join "<<a/m<<" "<<a%m<<" "<<b/m<<" "<<b%m<<endl;
        par[b] = a;
        per[a] += per[b];
    }
}

bool is_valid(int x, int y){
    if(x < 0 || x >= n) return false;
    return y>=0 && y<m-(x&1);
}

void set_active(int x, int y){
    map<int, int> mep;
    b[x][y] = 1;
    per[x*m + y] = 6;
    int curr_par = x*m + y;
    for(int k=0;k<6;++k){
        int xx = x+dx[k];
        int yy = y+dy[x&1][k];
        if(is_valid(xx, yy) && b[xx][yy]){
            mep[find_set(xx*m + yy)]++;
        }
    }
    for(const pii & x : mep){
        union_set(x.fi, curr_par);
        curr_par = find_set(curr_par);
        per[curr_par] -= x.se * 2;
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;++i){
        for(int j=0;j<m - (i&1);++j){
            par[i*m + j] = i*m+j;
            per[i*m + j] = 6;
            scanf("%d", a[i]+j);
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m - (i&1);++j){
            if(a[i][j] == 1){
                set_active(i, j);
            }
        }
    }
    // for(int i=0;i<n;++i){
    //     for(int j=0;j<m - (i&1);++j){
    //         cerr<<per[find_set(i*m+j)]<<" ";
    //     }
    //     cerr<<endl;
    // }
    scanf("%d", &q);
    while(q--){
        char c[10];
        int e, f;
        scanf("%s %d %d", c, &e, &f);
        --e, --f;
        if(c[0] == 'a'){
            set_active(e, f);
            // for(int i=0;i<n;++i){
            //     for(int j=0;j<m - (i&1);++j){
            //         cerr<<per[find_set(i*m+j)]<<" ";
            //     }
            //     cerr<<endl;
            // }
        }
        else {
            int currpar = find_set(e*m + f);
            printf("%d\n", b[e][f] ? per[currpar] : 0);
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