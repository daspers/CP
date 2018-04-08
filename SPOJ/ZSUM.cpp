#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;

const ll mod = 10000007;
const double pi = acos(-1);

int n,t,j,i,k,m;

ll powall(int a){
	ll p[33];
	p[0] = a;
	for(int i=1;i<32;i++)
		p[i] = (p[i-1]*p[i-1])%mod;
	ll res1 = 1;
	for(int i=0;a;i++){
		if(a&1){
			res1 *= p[i];
			res1 %= mod;
		}
		a>>=1;
	}
	ll res2 = 1;
	int temp = k;
	for(int i=0;temp;i++){
		if(temp&1){
			res2 *= p[i];
			res2 %= mod;
		}
		temp>>=1;
	}
	return (res1 + res2)%mod;
}

int main(){
	while(scanf("%d %d", &n, &k), n>0 && k>0){
		printf("%lld\n", (powall(n) + 2*powall(n-1)) % mod);
	}
	return 0;
}