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
typedef pair<int, int> pii;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
int r, v;
int a[102];

int main(){
	scanf("%d %d %d", &n, &r, &v);
	for(i=0;i<n;++i)
		scanf("%d", a+i);
	double ans = 0;
	for(i=0;i<n;++i){
		if(a[i]==v){
			puts("-1");
			return 0;
		}
		ans = max(ans, fabs(1.0*r/(v-a[i])));
	}
	printf("%.9lf\n", ans);
	return 0;
}