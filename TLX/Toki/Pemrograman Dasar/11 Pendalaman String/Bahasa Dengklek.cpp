#include <iostream>
#include <string>

using namespace std;

int main(){
	string a,b="";
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]<91) b+=a[i]+32;
		else if(a[i]>96) b+=a[i]-32;
		else b+=a[i];
			
	}
	cout<< b<<endl;
	return 0;
}
