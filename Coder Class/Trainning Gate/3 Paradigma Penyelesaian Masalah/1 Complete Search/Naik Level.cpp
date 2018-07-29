#include <iostream>
#include <math.h>

using namespace std;

bool *x;

uint64_t combin(long a, long b){
	uint64_t x=1;
	while(a>b)
		x*=a--;
	while(b>0)
		x/=b--;
	return x;
}

void sum(long *c, long a, long b, long *d, uint64_t &f, long v, int in){
	if(a-in<b){
		return;
	}
	else if(b==0){
		d[f++]=v;
		return;
	}
	else{
		for(int i=in;i<a;i++){
			if(!x[i]){
				x[i]=true;
				sum(c, a, b-1, d, f, v+c[i], i+1);
				x[i]=false;
			}
		}
	}
}

int main(){
	long a,b,*d;
	bool found = false;
	uint64_t s,f;
	cin>>a>>b;
	long *c=new long[a];
	s= combin(a, a/2);
	d=new long [s];
	x=new bool [a];
	for(int i=0;i<a;i++){
		cin>>c[i];
		x[i]=false;
	}
	for(int i=0;i<s;i++){
		d[i]=0;
	}
	for(long i=1;i<=a && !found;i++){
		f=0;
		sum(c, a, i, d, f, 0,0);
		for(int i=0;i<a;i++){
			x[i]=false;
		}
		for(int i=0;i<f&&!found;i++){
			if(d[i]==b)
				found=true;
		}
	}
	if (found)
		cout<<"bisa\n";
	else
		cout<<"tidak bisa\n";
	return 0;
}
