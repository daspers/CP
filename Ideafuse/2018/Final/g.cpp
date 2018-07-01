#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-9

typedef long long ll;
typedef complex<double> cd;
typedef pair<int, int> pii;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t,p;
int a[500002], dp[500002], maks[500002];

int main(){
	scanf("%d", &t);
	for(int cc=1;cc<=t;++cc){
		printf("Case #%d: ", cc);
		scanf("%d", &n);
		for(i=0;i<n;++i)
			scanf("%d", a+i);
		dp[n-2] = n-1;
		maks[n-1] = a[n-1];
		for(i=n-2;i>=0;--i){
			maks[i] = max(a[i], maks[i+1]);
		}
		for(i=n-3;i>=0;--i){
			dp[i] = i+1;
			while(dp[i] < n-1 && a[i] > a[dp[i]] && a[dp[i]]!=maks[i+1])
				dp[i] = dp[dp[i]];
		}
		int ans = 0, ma = 0;
		for(i=0;i<n-1;++i){
			int tmp = dp[i]-i;
			ma = max(ma, tmp);
			ans += tmp;
			ans %= mod;
		}
		printf("%d %d\n", ma, ans);
	}
	return 0;
}