#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1e9+7;
ll n,i,j,k,t,a;

int main(){
	scanf("%lld", &n);
	a = 1;
	t = 2;
	for(i=1;i<n;i++){
		a*=3;
		a%=mod;
		t+=a;
		t%=mod;
	}
	printf("%lld\n", t);
	return 0;
}
