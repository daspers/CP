#include <iostream>

using namespace std;

int main(){
	long x,i,a,max=-1e9;
	cin>>a;
	for(i=0; i<a;i++){
		cin>>x;
		if(max<x){
			max=x;
		}
	}
	cout<<max<<"\n";
	return 0;
}
