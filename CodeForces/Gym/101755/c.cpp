#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef unsigned long long ull;
 
const ll mod = 1e9+7;
const double pi = acos(-1);

int n,t,j,i,k;
pair<int, int> a[200005];

int main(){
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d %d", &(a[i].fi), &(a[i].se));
	}
	sort(a, a+n, [](const pair<int, int>& a, const pair<int, int>& b){
		if(a.fi == b.fi)
			return a.se > b.se;
		return a.fi < b.fi;
	});
	std::vector<pair<int, int>> ans;
	ans.pb(a[0]);
	for(i=1;i<n;i++){
		pair<int, int> temp = ans.back();
		if(a[i].fi <= temp.se){
			ans[ans.size()-1].fi = max(temp.fi, a[i].fi);
			ans[ans.size()-1].se = min(temp.se, a[i].se);
		}
		else{
			ans.pb(a[i]);
		}
		temp = ans.back();
		//printf("%d : %d %d\n",i, temp.fi, temp.se);
	}
	printf("%u\n", ans.size());
	for(auto& a : ans){
		printf("%d ", a.fi);
	}
	puts("");
	return 0;
}