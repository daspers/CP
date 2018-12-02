#include <bits/stdc++.h>

using namespace std;
#pragma GCC push_options
#pragma GCC optimize("O2")

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
int a[100000];
bool sudah[1000001];
int frek[9];
double has[1000001][9];
double psum[9][1000001];
// double has[9];
const ll wow = 1e13;

int main(){
	memset(sudah, false, sizeof sudah);
	for(j=1;j<=8;++j){
		psum[j][0] = sqrt(j*j);
		for(i=1;i<=1000000;++i)
			psum[j][i] = psum[j][i-1] + sqrt(j*j+4*i);
	}
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &k);
		double ans = 0;
		ll tmp = wow/k;
		long double val1 = 1.0*(tmp+1)/wow/2;
		long double val2 = 1.0*tmp/wow/2;
		int xx = wow % k;
		memset(frek, 0, sizeof frek);
		for(i=0;i<n;++i){
			// scanf("%d", a+i);
			getchar();
			++frek[getchar()-'0'];
		}
		if(!sudah[k]){
			for(i=1;i<=8;++i){
				long double tmp1 = 0, tmp2 = 0;
				long double apa = i*i;
				if(xx){
					tmp1 += psum[i][xx-1];
					tmp2 += psum[i][k-1] - psum[i][xx-1];
				}
				else tmp2 += psum[i][k-1];
				// cout<<tmp1<<" "<<tmp2<<endl;
				tmp1 += 1.0*(xx)*i;
				tmp2 += 1.0*(k-xx)*i;
				tmp1 *= val1;
				tmp2 *= val2;
				has[k][i] = tmp1 + tmp2;
			}
			sudah[k] = true;
		}
		for(i=1;i<=8;++i)
			ans += frek[i]*has[k][i]/n;
		printf("%.4lf\n", ans);
	}
	return 0;
}