#include <iostream>
#include <string>
using namespace std;

int main(){
	string a,b="";
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]==95) b+=a[++i]-32;
		else if(a[i]>64 && a[i]<91) b+='_',b+=a[i]+32;
		else b+=a[i];
			
	}
	cout<< b<<endl;
	return 0;
}
