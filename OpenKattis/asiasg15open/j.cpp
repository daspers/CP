#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
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

unsigned int n,i,j,k,t;
vector<unsigned int> adj[300001];
unsigned int len = 0, q;
unsigned int c[300001], st[300001], nd[300001];
unsigned int sz[300001], p[300001];
pll tree[1200001];
unsigned int ql, qr, col, idx;

void dfs(unsigned int v){
	nd[len] = v;
	st[v] = len++;
	sz[v] = 1;
	for(unsigned int x : adj[v]){
		dfs(x);
		sz[v] += sz[x];
	}
}

void build(unsigned int l, unsigned int r, unsigned int pos){
	if(l == r){
		if(c[nd[l]] >= 50){
			tree[pos].fi = 1LL << (c[nd[l]]-50);
			tree[pos].se = 0;
		}
		else{
			tree[pos].se = 1LL << (c[nd[l]]);
			tree[pos].fi = 0;
		}
		return;
	}
	unsigned int mid = (l+r)>>1;
	build(l, mid, 2*pos+1);
	build(mid+1, r, 2*pos+2);
	tree[pos] = {tree[2*pos+1].fi^tree[2*pos+2].fi, tree[2*pos+1].se^tree[2*pos+2].se};
}

void update(unsigned int l, unsigned int r, unsigned int pos){
	if(r < idx || l > idx)
		return;
	if(l == r){
		if(col >= 50)
			tree[pos].fi ^= 1LL<<(col-50);
		else
			tree[pos].se ^= 1LL<<col;
		return;
	}
	unsigned int mid = (l+r)>>1;
	update(l, mid, 2*pos+1);
	update(mid+1, r, 2*pos+2);	
	if(col >= 50)
		tree[pos].fi ^= 1LL<<(col-50);
	else
		tree[pos].se ^= 1LL<<col;
}

pll query(unsigned int l, unsigned int r, unsigned int pos){
	if(r < ql || l > qr)
		return {0, 0};
	if(l >= ql && r <= qr)
		return tree[pos];
	unsigned int mid = (l+r)>>1;
	pll t1 = query(l, mid, 2*pos+1);
	pll t2 = query(mid+1, r, 2*pos+2);
	return {t1.fi^t2.fi, t1.se^t2.se};
}

int main(){
	scanf("%u %u", &n, &q);
	for(i=0;i<n;++i){
		scanf("%u", c+i);
		--c[i];
	}
	for(i=1;i<n;++i){
		scanf("%u", p+i);
		adj[--p[i]].pb(i);
	}
	dfs(0);
	build(0, n-1, 0);
	// cout<<"shit\n";
	while(q--){
		unsigned int co, node;
		scanf("%u %u", &co, &node);
		--node;
		if(co){
			--co;
			if(co != c[node]){
				idx = st[node];
				col = c[node];
				update(0, n-1, 0);
				col = co;
				update(0, n-1, 0);
				c[node] = co;
			}
		}
		else{
			unsigned int ans = 0;
			ql = st[node];
			qr = st[node] + sz[node] -1;
			pll temp = query(0, n-1, 0);
			ans = __builtin_popcountll(temp.fi) + __builtin_popcountll(temp.se);
			printf("%u\n", ans);
		}
	}
	return 0;
};