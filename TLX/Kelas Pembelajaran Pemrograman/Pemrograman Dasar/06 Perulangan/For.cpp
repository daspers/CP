#include <iostream>

using namespace std;

int main(){
	int a;
	cin>>a;
	int c=0,d;
	for(int i=0;i<a;i++){
		cin>>d;
		c+=d;
	}
	cout<<c<<endl;
	return 0;
}
