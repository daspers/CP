#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e6;

ll a,b,r,c, p[40], n[40],i;

int main(){
	scanf("%lld %lld", &a, &b);
	c = b;
	for(i=0;i<36;i++){
		p[i] = c&1;
		c>>=1;
	}
	n[0]=a%mod;
	for( i=1;i<36;i++){
		n[i] = (n[i-1]*n[i-1])%mod;
	}
	for(r=1,i=0;i<36;i++){
		if(p[i]){
			r*=n[i];
			r%=mod;
		}
	}
	if((a == 2 && b>16)||(a==3&&b>10)||(a==4&&b>8)||(a==5&&b>7)||(a==6&&b>6)||(a>=7&&a<10&&b>5)||(a>9&&a<18&&b>4)||(a>17&&a<47&&b>3)||(a>46&&a<317&&b>2)||(a>316&&a<100000&&b>1)||(a>99999)){
		c=6;
		string x ="";
		while(c--){
			x= to_string(r%10)+x;
			r/=10;
		}
		cout<<x<<"\n";
	}
	else
		cout<<r<<"\n";
	return 0;
}
