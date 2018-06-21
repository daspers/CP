#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define INF 200000001
#define EPS 1e-9

typedef long long ll;
typedef complex<double> cd;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
int m;
bool path[1000002];
int cost[1000002], after[1000002];

int main(){
	memset(path, true, sizeof path);
	scanf("%d %d %d", &n, &m, &k);
	for(i=0;i<m;++i){
		scanf("%d", &t);
		path[t]=false;
	}
	for(i=1;i<=k;++i){
		scanf("%d", cost+i);
	}
	if(!path[0]){
		puts("-1");
		return 0;
	}
	int maxlen = 0, now = 0;
	for(i=1;i<n;++i){
		if(!path[i])
			now++;
		else{
			maxlen = max(maxlen, now);
			now = 0;
		}
	}
	if(now)
		maxlen = max(maxlen, now);
	if(maxlen >= k){
		puts("-1");
		return 0;
	}
	for(i=n;i>=0;--i){
		if(path[i])
			after[i] = i;
		else
			after[i] = after[i+1];
	}
	ll ans = 1e12+3;
	for(i = maxlen+1;i<=k;++i){
		int counter = 0;
		for(j=n;j>0;j=after[max(j-i, 0)])
			++counter;
		ans = min(ans, 1LL*counter*cost[i]);
	}
	printf("%lld\n", ans);
	return 0;
}