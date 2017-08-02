#include <iostream>
#include <string>
#include <vector>
using namespace std;

int backtrack(string a, string b){
	int i,j;
	for(i=a.size()-1,j=b.size()-1;i>=0&&j>=0;i--,j--){
		if(a[i]!=b[j])
			return i+1;
	}
	return i+1;
}

int fronttrack(string a, string b){
	int i,j;
	for(i=0,j=0;i<a.size()&&j<b.size();i++,j++){
		if(a[i]!=b[j])
			return i-1;
	}
	return i-1;
}

int main(){
	string a,b;
	cin>>a>>b;
	int i,j;
	i= fronttrack(a,b);
	j= backtrack(a,b);
	//cout<<i<<" "<<j<<endl;
	if(j-i<=2 && a.size()>1 && a.size()>b.size())
		cout<<"Tentu saja bisa!\n";
	else
		cout<<"Wah, tidak bisa :(\n";
	return 0;
}
