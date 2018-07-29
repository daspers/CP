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
int m;
int a[102][102], sum[102][102];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &n, &m, &k);
		for(i=1;i<=n;++i)
			for(j=1;j<=m;++j)
				scanf("%d", a[i]+j);
		for(i=0;i<=n;++i)
			sum[i][0] = 0;
		for(i=0;i<=m;++i)
			sum[0][i] = 0;
		for(i=1;i<=n;++i)
			for(j=1;j<=m;++j)
				sum[i][j] = a[i][j]-sum[i-1][j-1]+sum[i-1][j]+sum[i][j-1]; 
		int ans = 1;
		for(i=1;i<=n;++i){
			for(j=1;j<=m;++j){
				for(int x=n;x>=i;--x){
					if(ans >= (x-i+1)*(m-j+1))
						break;
					for(int y=m;y>=j;--y){
						if(ans >= (x-i+1)*(y-j+1))
							break;
						if(sum[x][y] + sum[i-1][j-1] - sum[i-1][y] - sum[x][j-1]>k)
							continue;
						ans = (x-i+1)*(y-j+1);
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}