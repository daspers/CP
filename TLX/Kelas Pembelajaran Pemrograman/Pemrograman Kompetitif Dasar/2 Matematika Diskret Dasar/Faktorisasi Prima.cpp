#include <iostream>

using namespace std;

int main(){
	long a,b,c;
	cin>>a;
	c=a;
	for(int i=2;i<=a && a>1;i++){
		if(a%i==0){
			b=1;
			a/=i;
			while(a%i==0){
				a/=i;
				b++;
			}
			cout<<i;
			if(b>1){
				cout<<"^"<<b;	
			}
			if(a>1)
				cout<<" x ";
		}
	}
	cout<<endl;
	return 0;
}
