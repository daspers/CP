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

int n,i,j,k,t;
int par[102];
double x[103], y[103];

int find_set(int v){
	if(v == par[v])
		return v;
	return par[v] = find_set(par[v]);
}

bool union_set(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(a != b){
		par[b] = a;
		return true;
	}
	return false;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(i=0;i<n;++i){
			scanf("%lf %lf", x+i, y+i);
			par[i] = i;
		}
		vector<pair<double, pii> > wew; 
		for(i=0;i<n;++i)
			for(j=i+1;j<n;++j)
				wew.pb({hypot(x[i]-x[j], y[i]-y[j]), {i, j}});
		sort(wew.begin(), wew.end());
		double ans = 0;
		for(i=0;i<wew.size();++i){
			if(union_set(wew[i].se.fi, wew[i].se.se))
				ans += wew[i].fi;
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}