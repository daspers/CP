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

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
int m,q;
int parent[100002];
int sized[100002];

int find_set(int v){
	if(v == parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}

void make_sets(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(a!=b){
		if(sized[a] < sized[b])
			swap(a, b);
		parent[b] = a;
		sized[a] += sized[b];
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for(i=1;i<=n;++i){
		parent[i] = i;
		sized[i] = 1;
	}
	for(i=0;i<m;++i){
		int x,y;
		scanf("%d %d", &x, &y);
		make_sets(x, y);
	}
	ll ans = 1;
	for(i=1;i<=n;++i){
		ans = max(ans, 1LL*sized[i]*sized[i]);
	}
	printf("%lld\n", ans);
	return 0;
}