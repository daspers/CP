#include <iostream>

using namespace std;

int main(){
	int x;
	cin >>x;
	for(int i=1;i<=x;i++){
		if(i%10<1) continue;
		else if(i>=42){cout<<"ERROR"<<endl;break;}
		else {cout<<i;}
		cout<<endl;
	}
	return 0;
}
