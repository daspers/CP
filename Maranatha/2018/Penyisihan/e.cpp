#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define eps 1e-9
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
int x[1002], y[1002];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		double totx=0, toty=0;
		for(i=0;i<n;++i){
			scanf("%d %d", x+i, y+i);
			totx += x[i];
			toty += y[i];
		}
		totx/=n;
		toty/=n;
		double pres = 0.1;
		double d, e;
		for(i=0;i<=30000;++i){
			int f = 0;
			d = pow(totx-x[0], 2) + pow(toty - y[0],2);
			for(j=1;j<n;++j){
				e = pow(totx-x[j], 2) + pow(toty-y[j],2);
				if(d < e)
					d = e, f = j;
			}
			totx += (x[f] - totx)*pres;
			toty += (y[f] - toty)*pres;
			pres *= 0.999;
		}
		printf("%.2lf %.2lf %.2lf\n", totx, toty, sqrt(d));
	}
	return 0;
}