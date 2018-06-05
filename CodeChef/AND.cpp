#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define INF 200000001
#define EPS 1e-9

typedef long long ll;
typedef complex<double> cd;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
int a[100002];
int bit[32];

int main(){
	memset(bit, 0, sizeof bit);
	scanf("%d", &n);
	for(i=0;i<n;++i){
		scanf("%d", a+i);
		int tmp = a[i];
		for(j=0;tmp;++j){
			if(tmp&1)
				bit[j]++;
			tmp >>= 1;
		}
	}
	ll ans = 0;
	for(i=0;i<32;++i){
		if(bit[i]>1){
			ans += (1<<i) * 1LL*bit[i]*(bit[i]-1)/2;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
