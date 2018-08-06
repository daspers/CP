#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-8
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define FastSlowInput ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
int a,b,c,d;
int cnt = 0;
std::vector<pii> p;
int dp[1000002], ma[1000002];

bool inside(int a, int b, int c, int d, int x, int y){
	if(a > c)
		swap(a, c);
	if(b > d)
		swap(b, d);
	return x>=a && x<=c && y>=b && y<=d;
}

int main(){
	scanf("%d", &n);
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int tot = 0;
	for(i=0;i<n;++i){
		int x, y;
		scanf("%d %d", &x, &y);
		if((x == a && y == b) || (x==c && y==d))
			tot++;
		else if(inside(a, b, c, d, x, y)){
			x = abs(c - x);
			y = abs(d - y);
			p.pb({x, y});
		}
	}
	a = abs(a - c);
	b = abs(b - d);
	c = d = 0;
	sort(p.begin(), p.end(), [](const pii &a, const pii &b){
		if(a.fi == b.fi)
			return a.se < b.se;
		return a.fi < b.fi;
	});
	p.pb({a, b});
	std::vector<int> lis;
	for(i=0;i<p.size();++i){
		std::vector<int>::iterator it = upper_bound(lis.begin(), lis.end(), p[i].se);
		if(it == lis.end())
			lis.pb(p[i].se);
		else
			*it = p[i].se;
	}
	printf("%d\n", tot + (int)lis.size() - 1);
	return 0;
}
