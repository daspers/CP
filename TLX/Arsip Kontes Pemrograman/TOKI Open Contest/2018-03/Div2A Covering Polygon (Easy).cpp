#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
 
const ll mod = 1e9+7;
const double pi = acos(-1);

int n,t,j,i,k;
int x[100003], y[100003];

int main(){
	scanf("%d", &n);
	for(i=0;i<n;i++)
		scanf("%d %d", x+i, y+i);
	x[n] = x[0];
	y[n] = y[0];
	for(i=1;i<=n;i++){
		if(x[i]!=x[i-1]&&y[i]!=y[i-1]){
			puts("TIDAK");
			return 0;
		}
	}
	puts("YA");
	return 0;
}