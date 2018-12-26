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
char a[500003], b[500003];

int main(){
    scanf("%d %d", &n, &k);
    scanf("%s", a);
    scanf("%s", b);
    ll ans = 0;
    ll diff = 0;
    for(i=0;i<n;++i){
        diff *= 2;
        diff += b[i] - a[i];
        if(diff > k) break;
        ans += min(diff+1, (ll) k);
    }
    ans += 1LL*(n-i) * k;
    printf("%lld\n", ans);
    return 0;
}