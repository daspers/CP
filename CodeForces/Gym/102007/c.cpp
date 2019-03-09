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

void printArray(int *arr, int n){
    for(int i=0;i<n;++i)
        printf("%d ", arr[i]);
    puts("");
}

int n,i,j,k,t;

int calc(int l, int w, int h){
    return 2 * (l*w + w*h + l*h);
}

int main(){
    scanf("%d", &n);
    int sq1 = sqrt(n);
    int l,w,h;
    int ans = 1e9;
    for(int i=1;i<=sq1;++i){
        if(n % i == 0){
            l = i;
            int now = n/i;
            int sq2 = sqrt(now);
            for(int j=1;j<=sq2;++j){
                if(now % j == 0){
                    w = j;
                    h = now/j;
                    ans = min(ans, calc(l, w, h));
                }
            }
            l = n/i;
            now = i;
            sq2 = sqrt(now);
            for(int j=1;j<=sq2;++j){
                if(now % j == 0){
                    w = j;
                    h = now/j;
                    ans = min(ans, calc(l, w, h));
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}