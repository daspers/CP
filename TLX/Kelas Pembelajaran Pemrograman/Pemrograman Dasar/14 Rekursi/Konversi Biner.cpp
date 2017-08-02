#include <iostream>

using namespace std;

string biner(unsigned long a){
	if(a==1)
		return "1";
	else{
		if(a%2)
			return biner(a/2)+"1";
		else
			return biner(a/2)+"0";
	}
}

int main(){
	unsigned long a;
	cin>>a;
	cout<<biner(a)<<endl;
	return 0;
}
