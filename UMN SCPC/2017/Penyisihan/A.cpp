//Encoding Problem

#include <bits/stdc++.h>

using namespace std;

char c[64]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
'0','1','2','3','4','5','6','7','8','9','+','/'};

int main(){
	int t,n,a;
	string k,r;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		cin>>k;
		printf("Case #%d: ",i);
		a=0,n=0;
		r="";
		for(int j=k.size()-1;j>=0;j--){
			if(n<5){
				if(k[j]=='1')
					a+=1<<n;
				n++;
			}
			else{
				if(k[j]=='1')
					a+=1<<n;
				r=c[a]+r;
				a=n=0;
			}
		}
		cout<<r<<"\n";
	}
	return 0;
}
