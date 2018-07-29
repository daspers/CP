#include <iostream>

using namespace std;

int main(){
	int a,b,n,x,y;
	uint64_t c=0,d=1e9+7;
	cin>>a>>b>>n;
	int64_t **m=new int64_t *[a];
	for(int i=0;i<a;i++){
		m[i]=new int64_t [b];
		for(int j=0;j<b;j++)
			m[i][j]=0;
	}
	for(int i=0;i<n;i++){
		cin>>x>>y;
		m[x-1][y-1]=-1;
	}
	m[0][0]=1;
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			if(m[i][j]>=0){
				if(i>0){
					if(m[i-1][j]>0)
						m[i][j]+=m[i-1][j];
				}
				if(j>0){
					if(m[i][j-1]>0)
						m[i][j]+=m[i][j-1];
				}
				m[i][j]%=d;
			}
		}
	}
	cout<<m[a-1][b-1]<<endl;
	return 0;
}
