#include <iostream>

using namespace std;

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	int m[a][b],n[b][c];
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++) cin>> m[i][j];
	}
	for(int i=0;i<b;i++){
		for(int j=0;j<c;j++) cin>> n[i][j];}
	int o[a][c];
	for(int i=0;i<a;i++){
		for(int j=0;j<c;j++){
			o[i][j]=0;
			for(int k=0;k<b;k++){
				o[i][j]+=m[i][k]*n[k][j];
			}
			cout<<o[i][j];
			if(j<c-1) cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}
