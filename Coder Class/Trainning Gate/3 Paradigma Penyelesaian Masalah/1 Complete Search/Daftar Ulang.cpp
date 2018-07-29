#include <iostream>
#include <vector>

using namespace std;

int main(){
	int a, b;
	cin>>a>>b;
	string s[a],t;
	for(int i=0;i<a;i++){
		cin>>s[i];
	}
	for(int i=0,j;i<b;i++){
		cin>>t;
		for(j=0;j<a;j++){
			if(s[j]==t){
				cout<<j+1<<endl;
				break;
			}
		}
		if(j==a)
			cout<<-1<<endl;
	}
	return 0;
}
