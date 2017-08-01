#include <iostream>

using namespace std;

long long ff(int a){
	if(a==1)
		return 1;
	if(a%2==0)
		return ff(a-1)*(a/2);
	return a*ff(a-1);
}

int main(){
	int a;
	cin>>a;
	cout<<ff(a)<<endl;
	return 0;
}
