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
pii a[300002];
int ans[300002];
set<int> s;

int main(){
	scanf("%d %d", &n, &k);
	for(i=0;i<n;++i){
		scanf("%d", &a[i].fi);
		a[i].se = i+1;
		s.insert(k+i+1);
	}
	sort(a, a+n, greater<pii>());
	ll sum = 0;
	for(i=0;i<n;++i){
		int val = *s.lower_bound(a[i].se);
		sum += 1LL*(val - a[i].se) * a[i].fi;
		ans[a[i].se-1] = val;
		s.erase(val);
	}
	printf("%lld\n", sum);
	for(i=0;i<n;++i)
		printf("%d ", ans[i]);
	puts("");
	return 0;
}
