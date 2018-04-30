#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
 
const ll mod = 1e9+7;
const double pi = acos(-1);

int n,t,i,j,k;
int a,b;
vector<int> v[1002];

int main(){
	scanf("%d", &n);
	for(i=1;i<n;i++){
		scanf("%d %d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}
	int ans = 0;
	for(i=1;i<=n;i++){
		if(v[i].size()==1)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
} 