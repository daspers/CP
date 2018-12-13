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

int n,i,j,k,t;
const int c = 1e7;

int main(){
    scanf("%d", &n);
    for(i=0;i<2;++i){
        int ans = 0;
        n = (217LL*n + 7*'a') % mod;
        while(n % c || n == 0){         
            if(n == 0){
                ans = c;
                n = c;
            }
            else if(n % c != 0){
                while(n%c){
                    int tmp = c-n%c;
                    ans += tmp;
                    n += tmp;
                    n %= mod;
                }
            }
        }
        printf("a %d\n", ans);
    }
    return 0;
}