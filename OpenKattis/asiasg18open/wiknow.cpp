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
int a[400002];
vector<int> pos[400002];
pii tree[1600004];

pii merge(pii a, pii b){
	if(a > b)
		swap(a, b);
    if(a.se <= b.fi || a==b)
        return a;
    pii ans = a;
	if(ans.se > b.fi && b.fi != a.fi)
		ans.se = b.fi;
	else if(ans.se > b.se)
		ans.se = b.se;
	return ans;
}

void build(int l, int r, int pos){
    if(l == r){
        tree[pos] = {a[l], n+2};
        return;
    }
    int mid = (l+r)/2;
    build(l, mid, 2*pos+1);
    build(mid+1, r, 2*pos+2);
    tree[pos] = merge(tree[2*pos+1], tree[2*pos+2]);
}

void deprecated_update(int l, int r, int pos, int idx){
    if(l > idx || r < idx)
        return;
    if(l == r){
        tree[pos] = {n+1, n+2};
        return;
    }
    int mid = (l+r)/2;
    deprecated_update(l, mid, 2*pos+1, idx);
    deprecated_update(mid+1, r, 2*pos+2, idx);
    tree[pos] = merge(tree[2*pos+1], tree[2*pos+2]);
}

pii query(int l, int r, int pos, int ql, int qr){
    if(l > qr || r < ql){
        return {n+1, n+2};
    }
    if(l>=ql && r<=qr){
        return tree[pos];
    }
    int mid = (l+r)/2;
    pii a = query(l, mid, 2*pos+1, ql, qr);
    pii b = query(mid+1, r, 2*pos+2, ql, qr);
    return merge(a, b);
}

int main(){
    scanf("%d", &n);
    for(i=0;i<n;++i){
        scanf("%d", a+i);
        pos[a[i]].pb(i);
    }
	build(0, n-1, 0);
    pii ans = {n+1, n+2};
    for(i=0;i<n;++i){
        if(pos[a[i]].back() == i){
			for(int x : pos[a[i]]){
				deprecated_update(0, n-1, 0, x);
			}
        }
		if(pos[a[i]].front() == i || pos[a[i]].front()+1 == i) continue;
		pii hasil = query(0, n-1, 0, pos[a[i]].front()+1, i-1);
		if(hasil.fi <= n){
			if(hasil.fi != a[i]){
				ans = min(ans, {a[i], hasil.fi});
			}
			else if(hasil.se <= n){
				ans = min(ans, {a[i], hasil.se});
			}
		}
    }
    if(ans.fi > n)
        puts("-1");
	else
		printf("%d %d\n", ans.fi, ans.se);
    return 0;
}