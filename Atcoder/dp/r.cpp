#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-9
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9+7;
const double PI = acos(-1);

struct matrix{
    int mat[50][50];
    int sz;
    void identity(){
        memset(mat, 0, sizeof mat);
        for(int i=0;i<sz;++i)
            mat[i][i] = 1;
    }
    matrix operator*(const matrix ot){
        matrix res;
        res.sz = sz;
        for(int i=0;i<sz;++i){
            for(int j=0;j<sz;++j){
                res.mat[i][j] = 0;
                for(int k=0;k<sz;++k){
                    res.mat[i][j] += 1LL * mat[i][k] * ot.mat[k][j] % mod;
                    res.mat[i][j] %= mod;
                }
            }
        }
        return res;
    }
    int sum(){
        int res = 0;
        for(int i=0;i<sz;++i){
            for(int j=0;j<sz;++j){
                res += mat[i][j];
                res %= mod;
            }
        }
        return res;
    }
    void print(){
        cout<<"print:"<<endl;
        for(int i=0;i<sz;++i){
            for(int j=0;j<sz;++j){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int n,i,j,k,t;
ll p;
matrix mat;
matrix pp[64];

int main(){
    scanf("%d %lld", &n, &p);
    mat.sz = n;
    for(i=0;i<n;++i){
        for(j=0;j<n;++j){
            scanf("%d", &mat.mat[i][j]);
        }
    }
    pp[0] = mat;
    for(i=1;i<64;++i){
        pp[i] = pp[i-1]*pp[i-1];
    }
    matrix res;
    res.sz = n;
    res.identity();
    for(i=0;p;++i){
        if(p&1){
            res = res * pp[i];
        }
        p>>=1;
    }
    printf("%d\n", res.sum());
    return 0;
}