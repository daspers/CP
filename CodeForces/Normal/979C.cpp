#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define Nmax 300000 

typedef long long ll;
typedef complex<double> cd;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t,m;
int a, b, ka, kb;
ll ans, hit;
vector<int> v[300002];

int hitung (int x, int p){
	int res = 1;
	for(int y : v[x]){
		if(y!=p)
			res += hitung(y, x);
	}
	return res;
}

bool leadsto(int x, int p, int y){
	if(x==y)
		return true;
	for(int t : v[x]){
		if(t!=p){
			bool iya = leadsto(t, x, y);
			if(iya)
				return true;
		}
	}
	return false;
}

int main(){
	scanf("%d %d %d", &n, &a, &b);
	for(i=1;i<n;++i){
		int x, y;
		scanf("%d %d", &x, &y);
		v[x].pb(y);
		v[y].pb(x);
	}
	ans = 1LL*n*(n-1);
	for(int x : v[a]){
		if(!leadsto(x, a, b)){
			ka += hitung(x, a);
		}
	}
	for(int x : v[b]){
		if(!leadsto(x, b, a)){
			kb += hitung(x, b);
		}
	}
	ans -= 1LL*(ka+1)*(kb+1);
	printf("%lld\n", ans);
	return 0;
}