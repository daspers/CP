#include <iostream>

using namespace std;

int main(){
	int x,p;
	cin >>x>>p;
	for(int i=1;i<=x;i++){
		if(i%p>0)
      			cout<<i;
		else
      			cout<<'*'; 
		if(i!=x)
      			cout<<" ";
	}
	cout<<endl;
	return 0;
}
