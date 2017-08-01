#include <iostream>
#include <string>

using namespace std;

int main(){
	long long a;
	string x;
	cin>>a;
	x=(a>0?"positif":a<0?"negatif":"nol");
	cout<<x<<endl;
	return 0;
}
