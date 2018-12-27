#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-9
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9+7;
const double PI = acos(-1);

int n,i,j,k,t;
int m;
int a[100004];
vector<pii> v;
int ac[100004];

int main(){
	memset(ac, 0, sizeof ac);
	scanf("%d %d", &n, &m);
	a[0] = 0;
	for(i=1;i<=n;++i)
		scanf("%d", a+i);
    sort(a+1, a+n+1);
    a[n+1] = 1e9;
    int cnt = 0;
	for(i=0;i<m;++i){
		int x1, x2, y;
		scanf("%d %d %d", &x1, &x2, &y);
        if(x1 > 1) continue;
		int idx2 = lower_bound(a, a+n+2, x2) - a ;
        if(a[idx2] > x2)
            idx2--;
        if(idx2 > 0){
            ac[idx2]++;
            cnt ++;
        }
	}
	int ans = 1e9;
	for(i=0;i<=n;++i){
        cnt -= ac[i];
		ans = min(ans, cnt + i);
    }
	printf("%d\n", ans);
	return 0;
}