#include <iostream>

using namespace std;

int main(){
	double a;
	long c;
	cin>>a;
	c=a;
	if(c==a) cout<<c<<" "<<c;
	else if(a>=0) cout<<c<<" "<<c+1;
	else cout<<c-1<<" "<<c;
	cout<<endl;
	return 0;
}
