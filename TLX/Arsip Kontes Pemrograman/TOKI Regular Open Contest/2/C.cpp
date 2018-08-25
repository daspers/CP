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

const ll mod = 998244353;
const double pi = acos(-1);

int n,i,j,k,t;
int p,v,d;
int x[2003], h[2003];
int tree[8005];

void build(int l, int r, int pos){
	if(l==r){
		tree[pos] = l;
		return;
	}
	int mid = (l+r)/2;
	build(l, mid, 2*pos+1);
	build(mid+1, r, 2*pos+2);
	int a = tree[2*pos+1];
	int b = tree[2*pos+2];
	tree[pos] = h[a] < h[b] ? a : b;
}

int query(int l, int r, int pos, int xl, int xr){
	if(xl > xr || l > xr || r < xl)
		return -1;
	if(l>=xl && r <= xr)
		return tree[pos];
	int mid = (l+r)/2;
	int a = query(l, mid, 2*pos+1, xl, xr);
	int b = query(mid+1, r, 2*pos+2, xl, xr);
	if(a==-1)
		return b;
	if(b==-1)
		return a;
	return h[a] < h[b]? a : b;
}

int main(){
	scanf("%d %d %d %d %d", &n, &p, &t, &v, &d);
	for(i=0;i<n;++i)
		scanf("%d", x+i);
	for(i=0;i<n;++i)
		scanf("%d", h+i);
	build(0,n-1,0);
	int now = 0, hi = t;
	ll ans = 0;
	h[n] = 2000;
	x[n] = 2e9;
	for(i=0;i<=n;){
		if(now < x[i]){
			int idx = query(0, n-1, 0, upper_bound(x, x+n, now-p)-x, i-1);
			if(idx == -1)
				now = x[i];
			else{
				hi = h[idx];
				int mi = min(p, min(x[idx] - (now-p), x[i]-now));
				if(hi < t){
					ans += 1LL*(t-hi)*d*mi;
				}
				now += mi;
			}
		}
		else ++i;
	}
	printf("%.8Lf\n", 1.0L*ans/v);
	return 0;
}