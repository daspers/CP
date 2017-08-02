#include <iostream>
#include <math.h>
using namespace std;


int main(){
	long a,b,k,x;
	cin>>a>>b>>k>>x;
	while(k--){
		x=abs(a*x+b);
	}
	cout<<x<<endl;
	return 0;
}
