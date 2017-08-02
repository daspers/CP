#include <iostream>

using namespace std;

int main(){
	int x,j=10;
	cin >>x;
	for(int i=1;i<=x;i++){
		int k=i;
		while(k--){cout<<j++%10;}
		cout<<endl;
	}
	return 0;
}
