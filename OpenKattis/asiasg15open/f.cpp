#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int n,i,j,k;
ii a[1002];

ii merge(ii a, ii b){
	return {max(a.fi, b.fi), min(a.se, b.se)};
}

int main(){
	scanf("%d", &n);
	for(i=0;i<n;++i)
		scanf("%d %d", &a[i].fi, &a[i].se);
	sort(a, a+n);
	int ans =0, sz = 0;
	int l,r;
	for(i=0;i<n;++i){
		if(sz==0){
			l = a[i].fi;
			r = a[i].se;
			sz = 1;
		}
		else{
			ii tmp = merge({l, r}, a[i]);
			if(tmp.fi <= tmp.se){
				l = tmp.fi;
				r = tmp.se;
			}
			else{
				++ans;
				sz = 1;
				l = a[i].fi;
				r = a[i].se;
			}
		}
	}
	printf("%d\n", ans+1);
	return 0;
};