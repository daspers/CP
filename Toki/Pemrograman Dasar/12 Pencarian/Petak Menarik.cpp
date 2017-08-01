#include <iostream>

using namespace std;


int main(){
	int n,m,k;
	cin >>n>>m>>k;
	int t[n][m];
	bool f =false;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>t[i][j];
		}
	}
	for(int j=0;j<m&&!f;j++){
		for(int i=0, z;i<n&&!f;i++){
			z=1;
			if(i>0)
				z*=t[i-1][j];
			if(j>0)
				z*=t[i][j-1];
			if(i<n-1)
				z*=t[i+1][j];
			if(j<m-1)
				z*=t[i][j+1];
			if(z==k){
				cout<<i+1<<" "<<j+1<<endl;
				f=true;
			}
		}
	}
	if(!f){
		cout<<"0 0\n";
	}
	return 0;
}
