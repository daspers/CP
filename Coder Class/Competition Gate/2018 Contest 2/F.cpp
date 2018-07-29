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
typedef pair<ll, ll> pii;

const ll mod = 1e9+7;
const double pi = acos(-1);

struct wosh{
	int pow;
	int k, s, m;
	wosh(){
		k=s=m=pow=0;
	}
	wosh(int _m, int _s, int _k, int _p){
		k = _k;
		s = _s;
		pow = _p;
		m = _m;
	}
	wosh& operator+= (const wosh &a) {
		s += a.s;
		k += a.k;
		m += a.m;
		pow += a.pow;
		return *this;
	}
};

int n,i,j,k,t;
int p,m,s;
int cb[105], po[105];
char st[20];
bool vis[105];
vector<int> ks;
int dp[101][16][16][16];
int par[102];
wosh wa[101];

int find_set(int a){
	if(par[a] == a)
		return a;
	return par[a] = find_set(par[a]);
}

void union_set(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(a!= b){
		par[b] = a;
		wa[a] += wa[b];
	}
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d %d %d", &n, &p, &k, &m, &s);
		for(i=1;i<=n;++i){
			par[i] = i;
			wa[i] = {0,0,0,0};
		}
		for(i=1;i<=n;++i){
			scanf("%s %d", st, po+i);
			if(!strcmp(st, "mandor"))
				wa[i].m++;
			else if(!strcmp(st, "kuli"))
				wa[i].k++;
			else
				wa[i].s++;
			wa[i].pow += po[i];
		}
		for(i=0;i<p;++i){
			int a,b,c;
			scanf("%d %d %d", &a, &b, &c);
			union_set(a, b);
			int x = find_set(a);
			wa[x].pow += c;
		}
		for(i=1;i<=n;++i)
			ks.pb(find_set(i));
		sort(ks.begin(), ks.end());
		ks.erase(unique(ks.begin(), ks.end()), ks.end());
		memset(dp, -1, sizeof dp);
		dp[0][0][0][0] = 0;
		for(i=0;i<ks.size();++i){
			for(int a=0;a<=m;a++)
				for(int b=0;b<=s;++b)
					for(int c=0;c<=k;++c)
						dp[i+1][a][b][c] = dp[i][a][b][c];
			wosh &tk = wa[ks[i]];
			if(tk.k > k || tk.m > m || tk.s > s)
				continue;
			for(int a = m-tk.m;a>=0;--a)
				for(int b = s-tk.s;b>=0;--b){
					for(int c = k-tk.k;c>=0;--c){
						if(dp[i][a][b][c] == -1)
							continue;
						if(dp[i+1][a+tk.m][b+tk.s][c+tk.k] == -1)
							dp[i+1][a+tk.m][b+tk.s][c+tk.k] = tk.pow + dp[i][a][b][c];
						else
							dp[i+1][a+tk.m][b+tk.s][c+tk.k] = max(dp[i+1][a+tk.m][b+tk.s][c+tk.k], tk.pow + dp[i][a][b][c]);
					}
				}
		}
		int ans = dp[ks.size()][m][s][k];
		if(ans < 0)
			puts("tidak mungkin");
		else
			printf("%d\n", ans);
		ks.clear();
	}
	return 0;
}