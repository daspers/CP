#include <iostream>
#include <string>
using namespace std;

int main(){
	int x;
	cin >>x;
	while(x>1){
		if(x%2) {
      			cout <<"bukan"<<endl;
      			return 0;
    		}
		x/=2;
	}
	cout<<"ya"<<endl;
	return 0;
}
