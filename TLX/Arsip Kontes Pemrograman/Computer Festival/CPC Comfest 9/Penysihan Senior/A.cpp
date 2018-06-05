#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define Nmax 300000 

typedef long long ll;
typedef complex<double> cd;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t,m;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		ll ans=0;
		for(i=0;i<n;++i){
			for(j=0;j<m;++j){
				scanf("%d", &k);
				ans += k;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}