#include <iostream>
#include <vector>

using namespace std;

int main(){
	int a[9];
	for(int i=0;i<9;i++){
		cin>>a[i];
	}
	for(int i=0;i<3;i++){
		cout<< a[i]<<" "<<a[i+3]<<" "<<a[i+6]<<endl;
	}
	return 0;
}
