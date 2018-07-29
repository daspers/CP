#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-9
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"

typedef long long ll;
typedef complex<double> cd;
typedef pair<int, int> pii;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
pii s[100002];
int dp[100002], sum[100002];

int lb(int val){
	int l = 0;
	int r = n;
	while(l < r){
		int mid = (l+r)>>1;
		if(s[mid].se >= val)
			r = mid;
		else
			l = mid+1;
	}
	return r;
}

int main(){
	scanf("%d", &n);
	for(i=0;i<n;++i)
		scanf("%d %d", &s[i].fi, &s[i].se);
	sort(s, s+n, [](const pii &a, const pii &b){
		if(a.se == b.se)
			return a.fi < b.fi;
		return a.se < b.se;
	});
	sum[0] = dp[0] = 1;
	for(i=1;i<n;++i){
		dp[i] = 1;
		int idx = lb(s[i].fi) -1;
		if(idx >= 0){
			dp[i] += sum[idx];
			dp[i] %= mod;
		}
		sum[i] = (sum[i-1] + dp[i]) % mod;
	}
	int ans = 0;
	for(i=0;i<n;++i){
		ans += dp[i];
		ans %= mod;
	}
	printf("%d\n", ans);
	return 0;
}