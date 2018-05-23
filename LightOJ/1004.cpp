#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define Nmax 300000 

typedef unsigned long long ll;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t,m;
int a[501][501], b[501][501];
ll dp[502][502];


int main(){
	scanf("%d", &t);
	for(int cc=1;cc<=t;++cc){
		printf("Case %d: ", cc);
		scanf("%d", &n);
		for(i=0;i<n;++i){
			for(j=0;j<=i;++j){
				scanf("%d", a[i]+j);
				int x,y;
				x=y=0;
				if(i>0){
					if(j>0)
						x = a[i-1][j-1];
					if(j<i)
						y = a[i-1][j];
				}
				a[i][j] += max(x, y);
			}
		}
		for(i=n;i<2*n-1;++i){
			for(j=0;j<=2*n-i-2;++j){
				scanf("%d", a[i]+j);
				int x,y;
				x = a[i-1][j+1];
				y = a[i-1][j];
				a[i][j] += max(x, y);
			}
		}
		printf("%d\n", a[2*n-2][0]);
	}
	return 0;
}