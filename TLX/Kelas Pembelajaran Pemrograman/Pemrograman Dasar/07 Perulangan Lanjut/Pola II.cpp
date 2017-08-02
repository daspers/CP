#include <iostream>

using namespace std;

int main(){
	int x;
	cin >>x;
	for(int i=x-1;i>=0;i--){
		int d=i,e=x-i;
		while(d--) cout<<" ";
		while(e--) cout<<'*';
		cout<<endl;
	}
	return 0;
}
