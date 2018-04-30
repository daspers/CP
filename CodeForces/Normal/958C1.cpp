#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
 
const ll mod = 1e9+7;
const double pi = acos(-1);

int n,t,i,j,k;
ll a[100002], p;
ll ps[100002];


int main(){
	scanf("%d %lld", &n, &p);
	for(i=1;i<=n;i++){
		scanf("%lld", a+i);
	}
	ps[0] = 0;
	for(i=1;i<=n;i++){
		ps[i] = ps[i-1]+a[i];
	}
	ll ma = 0;
	for(i=1;i<n;i++){
		ma = max(ma, 
			(ps[i]-ps[0])%p + (ps[n]-ps[i])%p);
	}
	printf("%lld\n", ma);
	return 0;
}