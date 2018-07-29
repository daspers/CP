#include <iostream>

using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	long c[a][b], d[a][b], m;
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++)
			cin>>c[i][j];
	}
	m=c[0][0];
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			for(int k=i;k<a;k++){
				for(int l=j;l<b;l++){
					d[k][l]=c[k][l];
					if(k>i)
						d[k][l]+=d[k-1][l];
					if(l>j)
						d[k][l]+=d[k][l-1];
					if(l>j&&k>i)
						d[k][l]-=d[k-1][l-1];
					if(d[k][l]>m)
						m=d[k][l];
						
				}
			}
		}
	}
	cout<<m<<endl;
	return 0;
}
