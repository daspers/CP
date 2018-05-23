#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define Nmax 300000 

typedef long long ll;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t,m;
int a[100002];

int main(){
	scanf("%d", &n);
	for(i=0;i<n;i++)
		scanf("%d", a+i);
	int l,r;
	l=0,r=1;
	int ans = 1;
	while(r<n){
		if(a[r-1] > a[r]){
			ans = max(ans, r-l);
			l = r;
		}
		++r;
	}
	ans = max(ans, r-l);
	printf("%d\n", ans);
	return 0;
}