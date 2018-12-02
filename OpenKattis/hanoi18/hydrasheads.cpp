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
int a,b;

int main(){
    while(scanf("%d %d", &a, &b), a>0 || b>0){
        if(b==0){
            if(a&1)
                puts("-1");
            else
                printf("%d\n", a/2);
        }
        else{
            int ans = 0;
            while(b>0){
                if(b&1){
                    b++;
                    ans++;
                }
                else if((a+b/2)&1)
                    b++, ans++;
                else{
                    ans += b/2;
                    a += b/2;
                    b=0;
                }
            }
            ans += a/2;
            printf("%d\n", ans);
        }
    }
    return 0;
}