#include <bits/stdc++.h>

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

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
int a[1002], m;
int dp[30001];

int main(){
	memset(dp, -1, sizeof dp);	
	scanf("%d %d", &n, &m);
	for(i=0;i<n;++i)
		scanf("%d", a+i);
	dp[0] = 0;
	for(i=0;i<n;++i){
		for(j=m-a[i];j>=0;--j){
			if(dp[j]!=-1){
				if(dp[j+a[i]]==-1)
					dp[j+a[i]] = 1+dp[j];
				else
					dp[j+a[i]] = min(dp[j+a[i]], 1+dp[j]);
			}
		}
	}
	printf("%d\n", dp[m]);
	return 0;
}