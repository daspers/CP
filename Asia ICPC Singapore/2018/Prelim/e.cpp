#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-8
#define EPS 1e-8
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
int a[61][31];
int h;
int dp[15][1<<15];
int c, d;
int malen;

int coba(int idx, int b){
	if(idx == malen)
		return 1e6;
	int &ans = dp[idx][b];
	if(ans == -1){
		int tmp = 1;
		for(int i=0;i<malen;++i){
			if(b & tmp){
				ans = max(ans, min(a[c+idx][d+i], coba(idx+1, b ^ tmp)));
			}
			tmp <<= 1;
		}
	}
	return ans;
}

int solve(int x, int y, int len){
	if(len == 1)
		return a[x][y];
	malen = len;
	c = x;
	d = y;
	memset(dp, -1, sizeof dp);
	return coba(0, (1<<len)-1);
}

int main(){
	scanf("%d", &n);
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			scanf("%d", a[i]+j);
			a[i+n][j] = a[i][j];
		}
	}
	h = (n+1)/2;
	int ans = 0;
	if(n & 1){
		for(i=0;i<=n/2;++i){
			ans = max(ans,
					max(min(solve(i, 0, h), solve(i+h, h, n-h)),
						min(solve(i+h-1, 0, h), solve(i, h, n-h))));
			// cout<<i<<" "<<solve(i, 0, h)<<" "<<solve(i+h, h, n-h)<<" "<<solve(i+h-1, 0, h)<<" "<<solve(i, h, n-h)<<endl;
		}
	}
	else{
		for(i=0;i<=n/2;++i){
			ans = max(ans,
					max(min(solve(i, 0, h), solve(i+h, h, h)),
						min(solve(i+h, 0, h), solve(i, h, h))));
		}
	}
	printf("%d\n", ans);
	return 0;
}