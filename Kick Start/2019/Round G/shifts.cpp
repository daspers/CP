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
pii a[42];
pll sum[13][531441];
int p3[25];

int main(){
    p3[0] = 1;
    for(int i=1;i<=13;++i){
        p3[i] = 3 * p3[i-1];
    }
    scanf("%d", &t);
    for(int cc=1;cc<=t;++cc){
        scanf("%d %d", &n, &m);
        for(int i=1;i<=n;++i){
            scanf("%d", &a[i].fi);
        }
        for(int i=1;i<=n;++i){
            scanf("%d", &a[i].se);
        }
        ll ans = 0;
        if(n <= 12){
            sum[0][0] = {0, 0};
            for(int i=1;i<=n;++i){
                for(int j=0;j<3;++j){
                    int w = j+1;
                    int lol1 = 0, lol2 = 0;
                    if(w & 1) lol1 += a[i].fi;
                    if(w & 2) lol2 += a[i].se;
                    int now = p3[i-1] * j;
                    // debug4(i, j, lol1, lol2);
                    for(int k=0;k<p3[i-1];++k){
                        sum[i][now+k].fi = sum[i-1][k].fi + lol1;
                        sum[i][now+k].se = sum[i-1][k].se + lol2;
                    }
                }
            }
        }
        for(int i=0;i<p3[n];++i){
            if(sum[n][i].fi >= m && sum[n][i].se >= m) {
                // cerr<<i<<" "<<sum[n][i].fi<<" "<<sum[n][i].se<<endl;
                ans++;
            };
        }
        printf("Case #%d: %lld\n", cc, ans);
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