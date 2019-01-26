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
char s[10002];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        if(n == 180){
            puts("-1");
            continue;
        }
        int gc = __gcd(n, 180);
        int a = n / gc;
        int b = 180 / gc;
        int ans = -1;
        for(int i=1;;++i){
            int tmp = i * b;
            if(180*tmp - 360 >= n * tmp){
                ans = tmp;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}