#include <bits/stdc++.h>
 
using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
 
const int maxn = 2e5 + 4;
 
vector<vii> AdjList;
vi parent, depth, heavy, head, pos;
vector<vi> indexx;
int curPos;
int sz[maxn];
int w[maxn], tempW[maxn];
int akhir[maxn];
 
 
int dfs(int node, int p, int dalam) {
	sz[node] = 1;
	int maks = 0;
	depth[node] = dalam;
	for(int i=0;i<AdjList[node].size();i++){
		ii v = AdjList[node][i];
		int tetangga = v.first, berat = v.second;
 
		if(tetangga != p) {
			int idx = indexx[node][i];
			akhir[idx] = tetangga;
 
			parent[tetangga] = node;
			int ukuranTetangga = dfs(tetangga, node, dalam+1);
			sz[node] += ukuranTetangga;
			tempW[tetangga] = berat;
 
			if(maks < ukuranTetangga) {
				maks = ukuranTetangga;
				heavy[node] = tetangga;
			}
		}
 
	}
	return sz[node];
}
 
void decompose(int node, int h) {
	head[node] = h, pos[node] = curPos++;
 
	if(heavy[node] != -1) {
		decompose(heavy[node], h);
	}
 
	for(int i=0;i<AdjList[node].size();i++){
		ii v = AdjList[node][i];
		int tetangga = v.first, berat = v.second;
 
		if(parent[node] != tetangga && heavy[node] != tetangga) {
			decompose(tetangga, tetangga);
		}
	}
}
 
void assignWeight(int n) {
	for(int i=1;i<=n;i++){
		int posisi = pos[i];
		w[posisi] = tempW[i];
	}
}
 
ll st[4*maxn];
int ql, qr;
bool lazy[4*maxn];
 
int left(int n){return n<<1;}
int right(int n){return (n<<1) + 1;}
 
void build(int node, int l, int r) {
	if(l == r) {
		st[node] = w[l];
		return;
	}
	int mid = (l+r)/2;
	build(left(node), l, mid);
	build(right(node), mid+1, r);

	st[node] = st[left(node)]+st[right(node)];
}

ll query(int node, int l, int r) {
	if(lazy[node]){
		st[node] = 0;
		if(l != r){
			lazy[left(node)] = true;
			lazy[right(node)] = true;
		}
		lazy[node] = false;
	}
	if(qr < l || r < ql) {return 0;}
	if(ql <= l && r <= qr){return st[node];}
	int mid = (l+r)/2;
	ll ans1 = query(left(node), l, mid);
	ll ans2 = query(right(node), mid+1, r);

	return ans1 + ans2;
}

void update(int node, int l, int r, int idx, int val) {
	if(r < idx || l > idx){return;}
	if(idx == r && idx == l){
		st[node] = val;
		return;
	}
	int mid = (l+r)/2;
	update(left(node), l, mid, idx, val);
	update(right(node), mid+1, r, idx, val);
	st[node] = st[left(node)] + st[right(node)];
}

void updateRange(int node, int l, int r) {
	if(lazy[node]){
		st[node] = 0;
		if(l != r){
			lazy[left(node)] = true;
			lazy[right(node)] = true;
		}
		lazy[node] = false;
	}
	if(r < ql || l > qr){return;}
	if(l>=ql && r<=qr){
		st[node] = 0;
		if(l != r){
			lazy[left(node)] = true;
			lazy[right(node)] = true;
		}
		return;
	}
	int mid = (l+r)/2;
	updateRange(left(node), l, mid);
	updateRange(right(node), mid+1, r);
	st[node] = st[left(node)] + st[right(node)];
}

ll jawabQuery(int a, int b) {
	if(a == b){return 0;}
	ll ans = 0;
	for(; head[a] != head[b]; b = parent[head[b]]) {
		if(depth[head[a]] > depth[head[b]]) {
			swap(a,b);
		}
        ql = pos[head[b]];
        qr = pos[b];
		ll cur = query(1,1,curPos);
		updateRange(1,1,curPos);
		ans = ans + cur;
	}
	if(depth[a] > depth[b]) {
		swap(a,b);
	}
    
    ql = pos[a]+1;
    qr = pos[b];
	ll cur = query(1,1,curPos);
		updateRange(1,1,curPos);
	ans = ans + cur;
	return ans;
}

// void updateJalan(int a, int b) {
// 	if(a == b){return;}
// 	ll ans = 0;
// 	for(; head[a] != head[b]; b = parent[head[b]]) {
// 		if(depth[head[a]] > depth[head[b]]) {
// 			swap(a,b);
// 		}
// 		updateRange(1,1,curPos,pos[head[b]], pos[b]);
// 	}
// 	if(depth[a] > depth[b]) {
// 		swap(a,b);
// 	}
// 	updateRange(1,1,curPos,pos[a]+1, pos[b]);
// }

void preprocess() {
	int n = AdjList.size();
	parent = vi(n+1);
	depth = vi(n+1);
	heavy = vi(n+1, -1);
	head = vi(n+1);
	pos = vi(n+1);
 
	curPos = 1;
	dfs(1, -1,0);
	decompose(1,1);
	assignWeight(n);
	build(1,1,curPos);
}
 
int main(){

	int tc,i,j,n;
	
	int x[maxn], y[maxn];
	tc = 1;
	while(tc--){
		// cin>>n;
		clock_t start = clock();
		int q;
		scanf("%d %d",&n,&q);
		// printf("n: %d q: %d\n",n, q);
		AdjList.assign(n+1, vii());
		indexx.assign(n+1, vi());
		for(i=0;i<n-1;i++){
			int a,b,c;
			// cin>>a>>b>>c;
			scanf("%d %d %d",&a,&b,&c);
			indexx[a].pb(i+1);
			indexx[b].pb(i+1);
			// mapper[ii(minim, maks)] = i+1;
			AdjList[a].pb(ii(b,c)); AdjList[b].pb(ii(a,c));
		}
		cerr<<"input "<<double(clock() - start) / double(CLOCKS_PER_SEC)<<"\n";
 
		preprocess();
		cerr<<"preprocess "<<double(clock() - start) / double(CLOCKS_PER_SEC)<<"\n";
 		
		char kata[10];
		// printf("q: %d\n",q);
		while(q--){
			int a,b;
			// cin>>a>>b;
			scanf("%d %d",&a,&b);
			// printf("kata: "); cout<<kata; printf(" %d %d\n",a,b);
			printf("%lld\n",jawabQuery(a,b));
			// jawabQuery(a,b);
		}
		cerr<<"queries "<<double(clock() - start) / double(CLOCKS_PER_SEC)<<"\n";
	}
	return 0;
};