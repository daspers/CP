#include <iostream>
#include <stdio.h>

using namespace std;

uint64_t gcd (uint64_t a, uint64_t b){
	uint64_t r=a%b;
	while(r){
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}

uint64_t count(uint64_t a, uint64_t b, uint64_t c){
	uint64_t d=b*c;
	return a/b+a/c-(a*gcd(b,c))/d;
}

uint64_t find(uint64_t a, uint64_t b, uint64_t c){
	while(a%b&&a%c){
		a--;
	}
	return a;
}

int main(){
	uint64_t a,b,c,t,ma,mi,mid,r;
	cin>>a>>b>>c;
	if(b>c){
		t=b;
		b=c;
		c=t;
	}
	if(c%b){
		mi=0, ma=b*a;
		mid=(mi+ma)/2;
		r=count(mid,b,c);
		while(r!=a){
			if(r>a){
				ma=mid;
			}
			else
				mi=mid;
			mid=(mi+ma)/2;
			r=count(mid,b,c);
		}
		cout<<find(mid,b,c)<<"\n";
	}
	else{
		cout<<a*b<<"\n";
	}
	return 0;
}
