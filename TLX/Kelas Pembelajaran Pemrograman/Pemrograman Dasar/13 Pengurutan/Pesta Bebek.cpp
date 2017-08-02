#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

bool lesser(string a, string b){
	int i=0;
	while(a[i]==b[i]&&i<a.size()&&i<b.size()){
		i++;
	}
	if(i==a.size())
		return true;
	else if(i==b.size())
		return false;
	return a[i]<b[i];
}

int main(){
	int n,x,e=0,i;
	cin>>n;
	string *s;
	s = new string [n];
	string t;
	for(int k=0,i;k<n&&e<=n;k++){
		cin>>t;
		if(k==0){
			s[0]=t;
			cout<<"1\n";
		}
		else{
			for(i=0;i<k&&lesser(s[i],t);i++);
			cout<<i+1<<"\n";
			for(int j=k;j>i;j--){
				s[j]=s[j-1];
			}
			s[i]=t;
		}
	}
	delete[] s;
	return 0;
}
