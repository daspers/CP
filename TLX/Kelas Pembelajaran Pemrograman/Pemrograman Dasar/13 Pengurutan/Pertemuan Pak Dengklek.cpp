#include <iostream>
#include <string>

using namespace std;

bool lesser(string a, string b){
	if(a.size()<b.size())
		return true;
	else if(a.size()>b.size())
		return false;
	else{
		int i=0;
		while(a[i]==b[i]){
			i++;
		}
		return a[i]<b[i];
	}
}

int main(){
	int n,imin;
	cin>>n;
	string s[n],temp;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(int i=0;i<n-1;i++){
		imin=i;
		for(int j=i+1;j<n;j++){
			if(lesser(s[j],s[imin]))
				imin=j;
		}
		if(i!=imin){
			temp=s[i];
			s[i]=s[imin];
			s[imin]=temp;
		}
	}
	for(int i=0;i<n;i++){
		cout<<s[i]<<"\n";
	}
	return 0;
}
