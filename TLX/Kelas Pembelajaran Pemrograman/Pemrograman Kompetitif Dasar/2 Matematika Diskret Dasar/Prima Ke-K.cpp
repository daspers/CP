#include <iostream>
#include <math.h>

using namespace std;

long *b,*p;

bool isprime(long a, long b){
	for(long i=0;i<b&&p[i]<=sqrt(a);i++){
		if(a%p[i]==0)
			return false;
	}
	return true;
}

int main(){
	long a,ma=0,mi=77778;
	cin>>a;
	b=new long [a];
	for(long i=0;i<a;i++){
		cin>>b[i];
		if(b[i]>ma)
			ma=b[i];
		if(b[i]<mi)
			mi=b[i];
	}
	long x=0;
	p=new long [ma+1];
	p[0]=2;
	for(long i=3;x<ma;i++){
		if(isprime(i,x+1)){
			p[++x]=i;
		}
	}
	for(int i=0;i<a;i++)
		cout<<p[b[i]-1]<<"\n";
  delete[] b;
  delete[] p;
	return 0;
}
