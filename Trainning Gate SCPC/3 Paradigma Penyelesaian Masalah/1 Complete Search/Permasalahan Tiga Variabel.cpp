#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int a,b,c,s=0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n-i;j++){
			s++;
		}
	}
	cout<<s<<endl;
	return 0;
}
