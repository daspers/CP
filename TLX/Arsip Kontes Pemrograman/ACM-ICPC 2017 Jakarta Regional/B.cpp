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
int val[100002], side[100002], q, m;
bool vis[100002];
vector<int> adj[100002];
bool bisa;

void dfs(int v, int c){
	for(int u : adj[v]){
		if(vis[u]){
			if(side[u] == c)
				bisa = false;
			continue;
		}
		side[u] = c^1;
		vis[u] = true;
		dfs(u, c^1);
	}
}

int main(){
	bisa = true;
	scanf("%d %d", &n, &m);
	for(i=1;i<=n;++i)
		scanf("%d", val+i);
	for(i=0;i<m;++i){
		int x, y;
		scanf("%d %d", &x, &y);
		adj[x].pb(y);
		adj[y].pb(x);
	}
	side[1] = 0;
	memset(vis, false, sizeof vis);
	vis[1] = true;
	dfs(1, 0);
	scanf("%d", &q);
	if(bisa && n>1){
		multiset<pii> wa;
		multiset<pii>::iterator it, ot, ut;
		multiset<int> ca;
		for(i=1;i<=n;++i)
			wa.insert({val[i], side[i]});
		it = ot = wa.begin();
		for(++it;it!=wa.end();++it, ++ot){
			if(ot->se != it->se)
				ca.insert(abs(ot->fi - it->fi));
		}
		while(q--){
			int a,b,c;
			scanf("%d %d %d", &a, &b, &c);
			if(a){
				if(side[b] == side[c])
					puts("0");
				else
					printf("%d\n", *ca.begin());
			}
			else if(val[b] != c){
				ut = it = ot = wa.lower_bound({val[b], side[b]});
				if(ot != wa.begin())
					--ot;
				++ut;
				if(it != ot){
					if(it->se != ot->se)
						ca.erase(ca.lower_bound(abs(it->fi-ot->fi)));
				}
				if(ut != wa.end()){
					if(ut->se != it->se)
						ca.erase(ca.lower_bound(abs(ut->fi-it->fi)));
				}
				if(it != ot && ut != wa.end()){
					if(ot->se != ut->se)
						ca.insert(abs(ot->fi-ut->fi));
				}
				wa.erase(it);
				wa.insert({val[b]=c, side[b]});
				ot = ut = it = wa.lower_bound({val[b], side[b]});
				if(ot != wa.begin())
					--ot;
				++ut;
				if(ot != it){
					if(it->se != ot->se)
						ca.insert(abs(it->fi-ot->fi));
				}
				if(ut != wa.end()){
					if(ut->se != it->se)
						ca.insert(abs(it->fi-ut->fi));
				}
				if(ut != wa.end() && ot != it){
					if(ot->se != ut->se)
						ca.erase(ca.lower_bound(abs(ut->fi-ot->fi)));
				}
			}
		}
	}
	else{
		while(q--){
			int a,b,c;
			scanf("%d %d %d", &a, &b, &c);
			if(a)
				puts("0");
		}
	}
	return 0;
}