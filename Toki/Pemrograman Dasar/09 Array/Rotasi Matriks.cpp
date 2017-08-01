#include <iostream>

using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	int m[a][b];
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++) cin>>m[i][j];
	}
	for(int i=0;i<b;i++){
		for(int j=a-1;j>=0;j--) {cout<<m[j][i];if(j>0)cout<<" ";}
		cout<<endl;
	}
	return 0;
}
