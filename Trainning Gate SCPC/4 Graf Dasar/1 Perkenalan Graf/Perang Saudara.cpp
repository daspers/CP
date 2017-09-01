#include <iostream>

using namespace std;

int p[1001][1001]={0};

int main(){
	int n,u,v,q,c;
	long m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		p[u][v]=1;
		p[v][u]=1;
	}
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>u>>v;
		c=0;
		for(int i=1;i<=n;i++){
			if(p[u][i]&&p[i][v])
				c++;
		}
		cout<<c<<"\n";
	}
	return 0;
}
