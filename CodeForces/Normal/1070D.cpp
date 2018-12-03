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
int a[200002];
int m;

int main(){
    scanf("%d %d", &n, &k);
    for(i=0;i<n;++i)
        scanf("%d", a+i);
    int pre = 0;
    ll ans = 0;
    for(i=0;i<n;++i){
        int num = (a[i]+pre)/k;
        if(1LL*num * k < pre){
            ans += num+1;
            pre = 0;
        }
        else{
            ans += num;
            pre = a[i]+pre-num*k;
        }
    }
    if(pre)
        ans += (pre+k-1)/k;
    printf("%lld\n", ans);
}