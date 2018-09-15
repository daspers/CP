#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-8
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
int q;
ll arr[200002];
ll offset[500][500];
priority_queue<pair<pii, int>> query[500];
int len;

int main(){
	memset(arr, 0, sizeof arr);
	memset(offset, 0, sizeof offset);
	scanf("%d %d", &n, &q);
	len = sqrt(n+1)+1;
	while(q--){
		int pil;
		scanf("%d", &pil);
		if(pil==1){
			int d, a, b;
			scanf("%d %d %d", &a, &b, &d);
			if( b <= len){
				offset[b][a] += d;
			}
			else{
				for(i=a;i<=n;i+=b)
					arr[i] += d;
			}
		}
		else{
			int idx;
			scanf("%d", &idx);
			ll ans = arr[idx];
			for(i=1;i<=len;++i){
				ans += offset[i][idx%i];
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}