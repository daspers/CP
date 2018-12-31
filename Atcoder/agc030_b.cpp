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
int len;
ll l[200002];
ll r[200002];

int main(){
    scanf("%d %d", &len, &n);
    for(i=1;i<=n;++i){
        scanf("%d", a+i);
    }
    sort(a+1, a+n+1);
    l[0] = 0;
    for(i=1;i<=n;++i){
        l[i] = a[i] + l[i-1];
    }
    r[n+1] = 0;
    for(i=n;i>=1;--i){
        r[i] = len - a[i] + r[i+1];
    }
    ll ans = 0;
    for(i=1;i<=n;++i){
        int num = min(i-1, n-i);
        // ending i-1 - > i
        if(num < n-i){
            ans = max(ans, 2*(l[i-1] - l[i-1-num]) + 2*(r[i+1] - r[i+2+num]) + a[i]);
        }
        else{
            ans = max(ans, 2*(l[i-1] - l[i-1-num]) + 2*(r[i+1] - r[i+1+num]) + a[i]);
        }
        // ending i+1 - > i
        if(num < i-1){
            ans = max(ans, 2*(l[i-1] - l[i-2-num]) + 2*(r[i+1] - r[i+1+num]) + len - a[i]);
        }
        else{
            ans = max(ans, 2*(l[i-1] - l[i-1-num]) + 2*(r[i+1] - r[i+1+num]) + len - a[i]);
        }
    }
    printf("%lld\n", ans);
	return 0;
}