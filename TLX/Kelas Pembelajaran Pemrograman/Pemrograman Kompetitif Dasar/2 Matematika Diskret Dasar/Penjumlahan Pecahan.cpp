#include <iostream>

using namespace std;

long long gcd(long long a, long long b){
	long long r = a%b;
	while(r){
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}

int main(){
	long long a,b,c,d,e,f,t,k;
	cin>>a>>b>>c>>d;
	t=gcd(a,b);
	a/=t;
	b/=t;
	t=gcd(c,d);
	c/=t;
	d/=t;
	k=gcd(b,d);
	f=b*d/k;
	e=a*(d/k)+c*(b/k);
	cout<<e<<" "<<f<<"\n";
	return 0;
}
