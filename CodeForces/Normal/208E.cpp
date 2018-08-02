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
int m;
vector<int> child[100002];
int anc[100002][20];
vector<pii> query[100002];
int p[100002];
int ans[100002];
vector<int> *bx = NULL;

void dfs(int nd){
	vector<int> * ax = NULL;
	for(int x : child[nd]){
		dfs(x);
		if(ax == NULL)
			swap(ax, bx);
		else{
			if(ax->size() < bx->size())
				swap(ax, bx);
			for(int i=1;i<=bx->size();++i)
				(*ax)[ax->size() - i] += (*bx)[bx->size()-i];
			delete bx;
			bx = NULL;
		}
	}
	for(const pii &x : query[nd])
		ans[x.se] = (*ax)[ax->size() -x.fi] - 1;
	if(ax == NULL)
		ax = new vector<int>();
	ax->pb(1);
	bx = ax;
}

void sparsetable_preproccess(int nd){
	if(p[nd]){
		anc[nd][0] = p[nd];
		for(int i=1;i<20;++i){
			anc[nd][i] = anc[anc[nd][i-1]][i-1];
			if(!anc[nd][i])
				break;
		}
	}
	for(int x : child[nd])
		sparsetable_preproccess(x);
}

int main(){
	memset(anc, 0, sizeof anc);
	scanf("%d", &n);
	for(i=1;i<=n;++i){
		scanf("%d", p+i);
		if(p[i])
			child[p[i]].pb(i);
	}
	for(i=1;i<=n;++i)
		if(!p[i])
			sparsetable_preproccess(i);
	scanf("%d", &m);
	for(i=0;i<m;++i){
		int x, y;
		scanf("%d %d", &x, &y);
		int now = x;
		int tmp = y;
		for(j=0;tmp;++j){
			if(tmp&1)
				now = anc[now][j];
			tmp >>= 1;
		}
		if(now)
			query[now].pb({y, i});
		else
			ans[now] = 0;
	}
	for(i=1;i<=n;++i)
		if(!p[i])
			dfs(i);
	for(i=0;i<m;++i)
		printf("%d ", ans[i]);
	puts("");
	return 0;
}