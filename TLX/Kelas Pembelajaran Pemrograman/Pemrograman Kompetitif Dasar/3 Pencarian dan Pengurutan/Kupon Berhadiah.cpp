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
typedef pair<ll, ll> pll;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;

int main(){
	scanf("%d %d", &n, &k);
	int diff = 1e6, ans = 1e6;
	for(i=0;i<n;++i){
		int x;
		scanf("%d", &x);
		if(abs(x-k) < diff){
			diff = abs(x-k);
			ans = x;
		}
		else if(abs(x-k)==diff)
			ans = min(ans, x);
	}
	printf("%d\n", ans);
	return 0;
}