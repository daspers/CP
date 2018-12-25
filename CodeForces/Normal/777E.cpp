#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-9
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"

typedef long long ll;
typedef complex<double> cd;
typedef pair<int, int> pii;
#define double long double

const ll mod = pow(2, 32);
const double PI = acos(-1);

struct ring{
	int a, b, h;
	ring(){a=b=h=0;}
	ring(int _a, int _b, int _h){
		a = _a; b = _b; h = _h;
	}
	bool operator< (const ring &x){
		if(b == x.b)
			return a < x.a;
		return b <x.b;
	}
};

int n,i,j,k,t;
ring a[100002];
ll dp[100002];
ll tree[400002];

void update(int l, int r, int pos, int idx, ll val){
	if(r < idx || l > idx)
		return;
	if(l==r){
		tree[pos] = val;
		return;
	}
	int mid = (l+r)>>1;
	update(l, mid, 2*pos+1, idx, val);
	update(mid+1, r, 2*pos+2, idx, val);
	tree[pos] = max(tree[2*pos+1], tree[2*pos+2]);
}

ll query(int l, int r, int pos, int ql, int qr){
	if(r < ql || l > qr)
		return 0;
	if(l>=ql && r<=qr)
		return tree[pos];
	int mid = (l+r)>>1;
	return max(query(l, mid, 2*pos+1, ql, qr), query(mid+1, r, 2*pos+2, ql, qr));
}

int binser(int val){
	int l = 0;
	int r = n;
	while(l<r){
		int mid = (l+r)>>1;
		if(a[mid].b <= val)
			r = mid;
		else
			l = mid+1;
	}
	return r;
}

int main(){
	memset(tree, 0, sizeof tree);
	memset(dp, 0, sizeof dp);
	scanf("%d", &n);
	for(i=0;i<n;++i)
		scanf("%d %d %d", &a[i].a, &a[i].b, &a[i].h);
	sort(a, a+n);
	reverse(a, a+n);
	dp[n] = 0;
	for(i=n-1;i>=0;--i){
		int idx = binser(a[i].a)-1;
		dp[i] = a[i].h;
		if(idx > i)
			dp[i] += query(0, n-1, 0, i+1, idx);
		update(0,n-1,0,i,dp[i]);
	}
	printf("%lld\n", *max_element(dp, dp+n));
	return 0;
}
