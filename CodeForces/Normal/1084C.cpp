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
char s[100002];
int cnt[100002];

int main(){
	memset(cnt, 0, sizeof cnt);
	scanf("%s", s);
	n = strlen(s);
	bool ada = false;
	for(j=i=0;i<n;++i){
		if(s[i] == 'a'){
			cnt[j] ++;
			ada = true;
		}
		else if(s[i] == 'b'){
			if(ada){
				j++;
				ada = false;
			}
		}
	}
	ll ans = 1;
	for(i=0;cnt[i];++i){
		// cout<<i<<" "<<cnt[i]<<endl;
		ans = (ans + ans * cnt[i]) % mod;
	}
	ans--;
	if(ans < 0)
		ans += mod;
	printf("%lld\n", ans);
	return 0;
}