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
int a[1000002], b[1000002];
int par[1000002];

int find_set(int v){
	if(v == par[v])
		return v;
	return par[v] = find_set(par[v]);
}

void union_set(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(a!=b){
		par[b] = a;
	}
}

int main(){
	scanf("%d %d", &n, &k);
	for(i=1;i<=n;++i)
		par[i] = i;
	for(i=0;i<k;++i){
		scanf("%d %d", a+i, b+i);
		union_set(a[i], b[i]);
	}
	for(i=1;i<=n/2;++i){
		if(find_set(i) != find_set(n-i+1))
			return puts("No") &0;
	}
	puts("Yes");
	return 0;
}