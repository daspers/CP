#include <iostream>

using namespace std;

int reverse(int x){
	int a=x,b=0;
	while(a){
		b=b*10+a%10;
		a/=10;
	}
	return b;
}

int main(){
	int a,b;
	cin>>a>>b;
	a=reverse(a);
	b=reverse(b);
	cout<<reverse(a+b)<<endl;
	return 0;
}
