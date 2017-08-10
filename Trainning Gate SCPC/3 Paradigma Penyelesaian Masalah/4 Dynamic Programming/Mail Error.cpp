#include <iostream>
#include <string>

using namespace std;

int main(){
	string a, b;
	cin>>a>>b;
	int l1=a.size()+1,l2=b.size()+1,m=1;
	int c[l1][l2];
	a=" "+a;
	b=" "+b;
	for(int i=0;i<l1;i++){
		for(int j=0;j<l2;j++){
			c[i][j]=0;
		}
	}
	for(int i=1;i<l1;i++){
		for(int j=1;j<l2;j++){
			if(a[i]==b[j]){
				c[i][j]=c[i-1][j-1]+1;
			}
			else{
				if(c[i-1][j]>=c[i][j-1]){
					c[i][j]=c[i-1][j];
				}
				else{
					c[i][j]=c[i][j-1];
				}
			}
		}
	}
	cout<<c[l1-1][l2-1]<<endl;
	return 0;
}
