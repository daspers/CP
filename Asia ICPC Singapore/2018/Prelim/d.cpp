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
int cnt[10002];
int par[10002];

int find_set(int v){
	if(v == par[v])
		return v;
	return par[v] = find_set(par[v]);
}

bool union_set(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(a!=b){
		
		return false;
	}
	return true;
}

int main(){
	scanf("%d %d", &n, &m);
	for(i=1;i<=n;++i)
		par[i] = i;
	for(i=0;i<m;++i){
		scanf("%d %d", a+i, b+i);
		
	}
	return 0;
}