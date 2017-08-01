#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int a, b,in;
	cin>>a>>b;
	double x[2][a],y[a],t[3];
	for(int i=0;i<a;i++){
		cin>>x[0][i];
	}
	for(int i=0;i<a;i++){
		cin>>x[1][i];
		y[i]=x[1][i]/x[0][i];
	}
	for(int i=0;i<a-1;i++){
		in=i;
		for(int j=i+1;j<a;j++){
			if(y[in]<y[j]){
				in=j;
			}
		}
		if(in!=i){
			t[0]=x[0][i];
			t[1]=x[1][i];
			t[2]=y[i];
			x[0][i]=x[0][in];
			x[1][i]=x[1][in];
			y[i]=y[in];
			x[0][in]=t[0];
			x[1][in]=t[1];
			y[in]=t[2];
		}
	}
	int k=0;
	double z=0;
	while(b>0&&k<a){
		if(b>=x[0][k]){
			b-=x[0][k];
			z+=x[1][k];
		}
		else{
			z+=y[k]*b;
			b=0;
		}
		k++;
	}
	cout<<fixed<<setprecision(5)<<z<<endl;
}
