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

pair<int, int> arr[100002], pre[200002];
int tot[200002];

int main(){
	int n,m;
	memset(pre, 0, sizeof pre);
	scanf("%d %d", &n, &m);
	for(int i=0;i<m;i++){
		int a, b;
		scanf("%d %d", &a, &b);
		arr[i] = {a, b};
	}
	for(int i=1;i<=n;i++){
		tot[i] = 1;
	}
	sort(arr, arr+m);
	for(int i=0;i<m;i++){
		int a = tot[arr[i].se];
		int b = tot[arr[i].se+1];
		tot[arr[i].se] += b - pre[arr[i].se].se;
		tot[arr[i].se+1] += a - pre[arr[i].se].fi;
		pre[arr[i].se] = {tot[arr[i].se],tot[arr[i].se+1]};
	}
	for(int i=1;i<=n;i++){
		printf("%d ", tot[i]);
	}
	puts("");
	return 0;
};