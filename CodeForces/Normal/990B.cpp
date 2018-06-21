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
set<int> s;
int exist[1000002];
int killed[1000003];

int main(){
	memset(killed, 0, sizeof killed);
	memset(exist, 0, sizeof exist);
	scanf("%d %d", &n, &k);
	for(i=0;i<n;++i){
		scanf("%d", &t);
		exist[t]++;
		killed[max(t-k, 1)]++;
		killed[t]--;
	}
	for(i=2;i<=1e6;++i)
		killed[i] += killed[i-1];
	int ans = 0;
	for(i=1;i<=1e6;++i){
		if(!killed[i])
			ans += exist[i];
	}
	printf("%d\n", ans);
	return 0;
}
