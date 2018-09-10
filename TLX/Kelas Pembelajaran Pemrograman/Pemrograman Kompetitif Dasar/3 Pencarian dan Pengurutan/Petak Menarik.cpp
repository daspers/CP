#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-8
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
int m;
int a[101][101];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int main(){
	scanf("%d %d %d", &n, &m, &k);
	for(i=0;i<n;++i)
		for(j=0;j<m;++j)
			scanf("%d", a[i]+j);
	int ans = 0, x=-1, y=-1;
	for(i=0;i<n;++i)
		for(j=0;j<m;++j){
			int tmp = 1;
			for(int l=0;l<4;++l){
				int xx = i + dx[l];
				int yy = j + dy[l];
				if(xx>=0 && xx<n && yy>=0 && yy<m)
					tmp *= a[xx][yy];
			}
			if(tmp == k){
				if(j<y || y==-1)
					x = i, y=j;
				else if(j==y)
					x = min(i, x);
			}
		}
	printf("%d %d\n", x+1, y+1);
	return 0;
}