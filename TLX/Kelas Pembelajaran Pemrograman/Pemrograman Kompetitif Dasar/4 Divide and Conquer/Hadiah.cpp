#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll p[20], mod;

ll fastexp(ll a){
	ll r, n[20], i;
	n[0]=a%mod;
	for(i=1;i<20;i++)
		n[i] = (n[i-1]*n[i-1])%mod;
	for(r=1,i=0;i<20;i++){	
		if(p[i]){
			r*=n[i];
			r%=mod;
		}
	}
	return r;
}

int main(){
	ll a, b, c, t, i;
	scanf("%lld %lld %lld %lld", &a, &b, &c, &mod);
	for(t=b,i=0;i<20;i++){
		p[i] = t&1;
		t>>=1;
	}
	t = a;
	while(c--){
		t = fastexp(t);
	}
	printf("%lld\n", t+1);
	return 0;
}
