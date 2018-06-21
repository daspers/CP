#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-9

typedef long long ll;
typedef complex<double> cd;
typedef pair<ll, ll> pii;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
int a[100002], b[100002];
bool vis[100002];
int main(){
	memset(vis, false, sizeof vis);
	scanf("%d", &n);
	for(i=0;i<n;++i){
		scanf("%d", a+i);
		b[i] = a[i];
	}
	sort(a, a+n);
	for(i=0;i<n;++i)
		b[i] = lower_bound(a, a+n, b[i])-a;
	vector<vector<int>> ans;
	for(i=0;i<n;++i){
		if(vis[i])
			continue;
		vector<int> tmp;
		int now = i;
		do{
			tmp.pb(now);
			vis[now] = true;
			now = b[now];
		}while(now!=i);
		ans.pb(tmp);
	}
	printf("%d\n", (int)ans.size());
	for(vector<int> &v : ans){
		printf("%d", (int)v.size());
		for(int x : v)
			printf(" %d", x+1);
		puts("");
	}
	return 0;
}