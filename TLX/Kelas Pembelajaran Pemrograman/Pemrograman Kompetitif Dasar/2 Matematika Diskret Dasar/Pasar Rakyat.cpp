#include <iostream>
#include <math.h>

using namespace std;

long gcd(long a, long b){
	long r=a%b;
	while(r){
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}

long lcm(long a, long b){
	long x = gcd(a,b);
	return a*b/x;
}

int main(){
	int a;
	cin>>a;
	long b[a];
	for(int i=0;i<a;i++)
		cin>>b[i];
	for(int i=0;i<a-1;i++)
		b[i+1]=lcm(b[i],b[i+1]);
	cout<<b[a-1]<<"\n";
	return 0;
}
