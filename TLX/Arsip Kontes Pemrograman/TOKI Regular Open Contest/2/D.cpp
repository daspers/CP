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

const ll mod = 998244353;
const double pi = acos(-1);

int n,i,j,k,t;
int x,y,c,d,m1,m2;
int a[50001], b[50001];
bool visa[50001], visb[50001];

int main(){
	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
	memset(visa, 0, sizeof visa);
	memset(visb, 0, sizeof visb);
	scanf("%d %d %d %d %d %d %d", &n, &x, &y, &c, &d, &m1, &m2);
	int now = x, lena = 1, lenb = 1, enda, endb, sta=0, stb=0;
	while(!visa[now]){
		sta++;
		visa[now] = true;
		now = now*c % m1;
	}
	enda = now;
	a[now] = 1;
	while((now = (now*c%m1)) != enda){
		a[now] = 1;
		lena++;
	}
	now=x;
	while(now != enda){
		sta++;
		now = now*c % m1;
	}
	now = y;
	while(!visb[now]){
		visb[now] = true;
		now = now*d%m2;
	}
	endb = now;
	b[now]=1;
	while((now=(now*d)%m2)!= endb)
		b[now]=1,lenb++;
	now = y;
	while(now!=endb){
		stb++;
		now = now*d%m2;
	}
	int da = max(n-sta, 0)/lena, db = max(n-stb, 0)/lenb;
	int sa = max(n-sta, 0)%lena, sb = max(n-stb, 0)%lenb;
	for(i=0;i<m1;++i)
		a[i] *= da;
	for(i=0;i<m2;++i)
		b[i] *= db;
	sa = min(sa + sta, n);
	sb = min(sb + stb, n);
	for(now=x,i=0;i<sa;++i){
		a[now]++;
		now = (now*c)%m1;
	}
	for(now = y,i=0;i<sb;++i){
		b[now]++;
		now = (now*d)%m2;
	}
	ll ans = 0;
	for(i=j=0;i<m1 && j<m2;){
		while(i<m1 && !a[i]) ++i;
		while(j<m2 && !b[j]) ++j;
		if(i == m1 || j == m2)
			break;
		int mi = min(a[i], b[j]);
		ans += 1LL*mi * i*j;
		a[i] -= mi;
		b[j] -= mi;
	}
	printf("%lld\n", ans);
	return 0;
}