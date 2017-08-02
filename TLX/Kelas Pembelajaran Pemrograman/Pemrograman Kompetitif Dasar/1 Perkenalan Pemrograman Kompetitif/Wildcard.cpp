#include <iostream>
#include <string>

using namespace std;

bool cekback(string a, string b, int c){
	int i=a.size()-1, j=b.size()-1;
	for(;i>c && j>=0;i--,j--){
		if(a[i]!=b[j])
			return false;
	}
	if(j<c-1||(j==-1&&i>c))
		return false;
	return true;
}

bool cekfront(string a, string b, int c){
	int i=0, j=0;
	for(;i<c && j<b.size();i++,j++){
		if(a[i]!=b[j])
			return false;
	}
	if(j>c||(j==b.size()&&i<c))
		return false;
	return true;
}

int main(){
	string a;
	int c,pos;
	cin>>a;
	cin>>c;
	string s[c];
	for(int i=0;i<c;i++){
		cin>>s[i];
	}
	for(int i=0;i<a.size();i++){
		if(a[i]=='*'){
			pos=i;
			break;
		}
	}
	int b;
	if(a=="*"){
		for(int i=0;i<c;i++)
			cout<<s[i]<<"\n";
	}
	else if(pos==0){
		for(int i=0;i<c;i++){
			if(cekback(a,s[i],pos))
				cout<<s[i]<<"\n";
		}
	}
	else if(pos==a.size()-1){
		for(int i=0;i<c;i++){
			if(cekfront(a,s[i],pos))
				cout<<s[i]<<"\n";
		}
	}
	else{
		for(int i=0;i<c;i++){
			if(cekfront(a,s[i],pos)&&cekback(a,s[i],pos))
				cout<<s[i]<<"\n";
		}
	}
	return 0;
}
