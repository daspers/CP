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
int a[100002];
vector<int> wew[100002];

int main(){
	scanf("%d", &t);
	for(int cc=1;cc<=t;++cc){
		printf("Case #%d: ", cc);
		scanf("%d", &n);
		for(i=0;i<n;++i){
			scanf("%d", a+i);
			wew[a[i]].pb(i);
		}
		ll ans = 0;
		for(i=1;i<=100000;++i){
			if(wew[i].size()>1){
				int tmp = wew[i].size();
				for(j=tmp-1;j>=0;--j)
					ans += 1LL*j*wew[i][j]-1LL*(tmp-1-j)*wew[i][j];
				ans -= 1LL*(tmp-1)*tmp/2;
			}
		}
		printf("%lld\n", ans%mod);
		for(i=1;i<=100000;++i)
			wew[i].clear();
	}
	return 0;
}