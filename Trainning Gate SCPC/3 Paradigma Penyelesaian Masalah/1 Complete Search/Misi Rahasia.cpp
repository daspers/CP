#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

bool associate(int **c, vector<int> x, int s, int b){
	for(int i=0;i<s;i++){
		if(c[x[i]][b] ==0)
			return false;
	}
	return true;
}

int main(){
	int a,b,m=0,t;
	vector<int> x;
	cin>>a>>b;
	int **c,d[b][2];
	c=new int*[a+1];
	for(int i=0;i<=a;i++){
		c[i]=new int [a+1];
		for(int j=0;j<=a;j++){
			c[i][j]=0;
		}
	}
	for(int i=0;i<b;i++){
		cin>>d[i][0]>>d[i][1];
		c[d[i][0]][d[i][1]]=1;
		c[d[i][1]][d[i][0]]=1;
	}
	for(int i=1;i<=a;i++){
		x.clear();
		x.push_back(i);
		for(int j=1;j<=a;j++){
			if(i!=j&&associate(c,x,x.size(),j)){
				x.push_back(j);
			}
		}
		if(x.size()>m)
			m=x.size();
	}
	cout<<m<<"\n";
	for(int i=0;i<=a;i++){
		delete[] c[i];
	}
	delete[] c;
	return 0;
}
