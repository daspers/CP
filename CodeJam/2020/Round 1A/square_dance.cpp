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

int n,m,k,t;
int a[1001][1001];

int main(){
    scanf("%d", &t);
    for(int cc=1;cc<=t;++cc){
        printf("Case #%d: ", cc);
        scanf("%d %d", &n, &m);
        ll totsum = 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                scanf("%d", a[i]+j);
                totsum += a[i][j];
            }
        }
        bool pass;
        ll ans = totsum;
        do {
            pass = false;
            vector<pii> torem;
            for(int i=0;i<n;++i){
                for(int j=0;j<m;++j){
                    if(!a[i][j]) continue;
                    int cnt = 0;
                    int sum = 0;
                    for(int k=j-1;k>=0;--k){
                        if(a[i][k]) {
                            sum += a[i][k];
                            cnt++;
                            break;
                        }
                    }
                    for(int k=j+1;k<m;++k){
                        if(a[i][k]) {
                            sum += a[i][k];
                            cnt++;
                            break;
                        }
                    }
                    for(int k=i+1;k<n;++k){
                        if(a[k][j]) {
                            sum += a[k][j];
                            cnt++;
                            break;
                        }
                    }
                    for(int k=i-1;k>=0;--k){
                        if(a[k][j]) {
                            sum += a[k][j];
                            cnt++;
                            break;
                        }
                    }
                    if(a[i][j] * cnt < sum){
                        torem.pb({i, j});
                    }
                }
            }
            for(const pii &x : torem){
                totsum -= a[x.fi][x.se];
                a[x.fi][x.se] = 0;
                pass = true;
            }
            if(pass) ans += totsum;
        } while(pass);
        printf("%lld\n", ans);
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