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
int a[100];
char lbl[100];

void readline(vector<string> &a){
	a.clear();
	string x = "";
	char c;
	while(c = getchar(), c!='\n'){
		if(c == ' '){
			if(x.size()>0)
				a.pb(x);
			x="";
		}
		else
			x += c;
	}
	if(x.size()>0)
		a.pb(x);
	for(const string &x : a)
		cout<<x<<endl;
}

int main(){
	while(scanf("%d %s", &n, lbl), n>0){
		map<string, int> cnt, book[n+1], frek;
		vector<string> wew;
		debug(n);
		for(i=1;i<n;++i){
			scanf("%d\n	", a+i);
			readline(wew);
			for(const string &x : wew){
				if(!book[i].count(x))
					cnt[x]++;
				book[i][x]++;
				frek[x]++;
			}
		}
		readline(wew);
		double cmap = -1e9;
		for(const string &x : wew){
			double tmp = 0;
			int tot=0;
			map<string, int> cc;
			for(i=1;i<n;++i){
				if(!book[i].count(x))
					continue;
				for(const pair<string, int> &y : book[i]){
					cc[y.fi] += y.se;
					tot += y.se;
				}
			}
			for(const pair<string, int> &y : cc){
				if(y.fi == x)
					continue;
				tmp += log10(1.0*y.se/tot);
			}
			tmp += log10(1.0*cnt[x]/n);
			cmap = max(cmap, tmp);
		}
		cout<<cmap<<endl;
	}
	return 0;
}