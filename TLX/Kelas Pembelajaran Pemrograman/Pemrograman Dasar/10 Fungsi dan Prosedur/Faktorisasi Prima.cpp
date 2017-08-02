#include <iostream>

using namespace std;


int main(){
	unsigned long a,b=1,c=1;
	cin>>a;
	for(unsigned long i=2;a>1;i++){
		if(a%i==0){
			if(b==i){
				c++;
			}
			else if(b==1) b=i;
			else{
				cout<<b;
				if(c>1) cout<<"^"<<c;
				cout<<" x ";
				c=1;
				b=i;
			}
			a/=i;
			i=1;
		}
	}
	cout<<b;
	if(c>1) cout<<"^"<<c;
	cout<<endl;
	return 0;
}
