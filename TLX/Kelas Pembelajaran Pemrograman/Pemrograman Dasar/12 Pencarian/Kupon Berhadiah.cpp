#include <iostream>

using namespace std;

int main(){
	long a,b;
	cin>>a>>b;
	long x;
	long t,diff=999999, num;
	for(long i=0;i<a;i++){
		cin>>x;
		t= b>x?b-x:x-b;
		if(t<diff){
			diff=t;
			num=x;
		}
		else if(t==diff){
			if(x<num)
				num=x;
		}
	}
	cout<<num<<endl;
	return 0;
}
