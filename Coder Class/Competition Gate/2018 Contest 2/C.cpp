#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-8
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<ll, ll> pii;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
double tot[55];
double nck[55][55];
double p[55], q[55];

int main(){
	tot[1] = 1;
	tot[0] = 0;
	nck[0][0] = nck[1][0] = nck[1][1] = 1;
	for(i=2;i<=50;++i)
		tot[i] = 2*tot[i-1]+1;
	for(i=2;i<=50;++i){
		nck[i][0] = nck[i][i] = 1;
		for(j=1;j<i;++j)
			nck[i][j] = nck[i-1][j] + nck[i-1][j-1];
	}
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &k);
		double ans = 0;
		p[0] = q[0] = 1;
		p[1] = k/100.0;
		q[1] = (100-k)/100.0;
		for(i=2;i<=n;++i){
			p[i] = p[1]*p[i-1];
			q[i] = q[1]*q[i-1];
		}
		for(i=1;i<=n;++i){
			ans += nck[n-1][i-1]*tot[n]*p[i]*q[n-i];
		}
		printf("%.9lf\n", ans);
	}
	return 0;
}