// #include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <vector>

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
#define double long double

const ll mod = 1e9+7;
const double PI = acos(-1);


int n,i,j,k,t;
int m, p;
pair<int, pii> a[300005];
int parent[1003], sized[1003];

int find_set(int v){
	if(v == parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(a!=b){
		if(sized[a] < sized[b])
			swap(a,b);
		parent[b] = a;
		sized[a] += sized[b];
	}
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		for(i=0;i<m;++i)
			scanf("%d %d %d", &a[i].se.fi, &a[i].se.se, &a[i].fi);
		sort(a, a+m);
		for(i=1;i<=n;++i){
			parent[i] = i;
			sized[i] = 1;
		}
		int ans = 0;
		vector<int> coba;
		for(i=0;i<m;++i){
			if(find_set(a[i].se.fi) != find_set(a[i].se.se)){
				ans += a[i].fi;
				union_sets(a[i].se.fi, a[i].se.se);
				coba.pb(i);
			}
		}
		bool unique = true;
		for(int w=0;w<coba.size();++w){
			int &x = coba[w];
			for(i=1;i<=n;++i){
				parent[i] = i;
				sized[i] = 1;
			}
			int tmp = 0, c=0;
			for(i=0;i<m;++i){
				if(i != x && find_set(a[i].se.fi) != find_set(a[i].se.se)){
					tmp += a[i].fi;
					union_sets(a[i].se.fi, a[i].se.se);
					c++;
				}
			}
			if(c!=n-1)
				continue;
			if(ans == tmp){
				unique = false;
				break;
			}
		}
		if(unique)
			printf("%d\n", ans);
		else
			puts("Not Unique!");
	}
	return 0;
}