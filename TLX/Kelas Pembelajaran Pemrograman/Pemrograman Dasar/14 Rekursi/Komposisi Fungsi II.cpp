#include <iostream>

using namespace std;

long ff(int a,int b,int c,long x){
	x = a*x+b;
	if(x<0)
		x=-x;
	if(c==1)
		return x;
	else
		return ff(a,b,c-1,x);
}

int main(){
	int a,b,c;
	long x;
	cin>>a>>b>>c>>x;
	cout<<ff(a,b,c,x)<<endl;
	return 0;
}
