#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
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
int m;
double dp[3001][3001];

double solve(int x, int y){
	double &ans = dp[x][y];
	if(ans < 0){
		ans = 1.0/(x+y);
		if(x)
			ans += 1.0*x/(x+y)*solve(x-1, y+1);
		if(y)
			ans += 1.0*y/(x+y)*solve(x, y-1);
	}
	return ans;
}

int main(){	
	for(i=0;i<=3000;++i)
		for(j=0;j<=3000;++j)
			dp[i][j] = -1;
	dp[0][0] = 0;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		map<int, int> mep;
		for(i=0;i<m;++i){
			scanf("%d", &k);
			mep[k]++;
		}
		int a, b;
		a = b = 0;
		for(const pii & x : mep){
			if(x.se>1) a++;
			else b++;
		}
		a = n - b - a;
		printf("%.9lf\n", n*solve(a, b));
	}
	return 0;
}