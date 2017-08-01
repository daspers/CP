#include <iostream>
#include <string>
using namespace std;

int main(){
	unsigned long x;
	cin >>x;
	for(int i=x;i>0;i--){
		if (x%i<1)
      			cout<<i<<endl;
	}
	return 0;
}
