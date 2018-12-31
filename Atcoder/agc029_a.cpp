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
char s[200002];
int cnt[200002];

int main(){
    scanf("%s", s);
    n = strlen(s);
    cnt[n] = 0;
    for(i=n-1;i>=0;--i)
        cnt[i] = cnt[i+1] + (s[i] == 'W');
    ll ans = 0;
    for(i=0;i<n;++i){
        if(s[i]=='B')
            ans += cnt[i];
    }
    printf("%lld\n", ans);
	return 0;
}