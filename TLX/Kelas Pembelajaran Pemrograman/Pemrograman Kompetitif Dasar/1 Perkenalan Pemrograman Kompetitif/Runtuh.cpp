#include <iostream>
#include <string>
#include <vector>
using namespace std;

string *s;
vector<int> c;

bool all1(string x){
	for(int i=0;i<x.size();i++){
		if(x[i]=='0')
			return false;
	}
	return true;
}

void change0(int a){
	for(int i=0;i<s[a].size();i++){
		s[a][i]='0';
	}
}

bool blockof1(int a){
	c.clear();
	bool b=false;
	for(int i=a-1;i>=0;i--){
		if(all1(s[i])){
			c.push_back(i);
			b=true;
		}
	}
	return b;
}

void collapse(int a, int b, int d){
	int m,n;
	for(int i=0;i<b;i++){
		m=d;
		n=d-1;
		while(m<a-1){
			if(s[m+1][i]=='1')
				break;
			else
				m++;
		}
		while(n>=0&&m>=0){
			if(s[n][i]=='1'){
				s[n][i]='0';
				s[m--][i]='1';
				//cout<<m<<", "<<n<<"\n";
			}
			n--;
		}
	}
}

int main(){
	int a,b;
	cin>>a>>b;
	s=new string[a];
	for(int i=0;i<a;i++){
		cin>>s[i];
	}
	while(blockof1(a)){
		for(int i=0;i<c.size();i++){
			change0(c[i]);
		}
		collapse(a,b,c[0]);
	}
	for(int i=0;i<a;i++){
		cout<<s[i]<<"\n";
	}
	delete[] s;
	return 0;
}
