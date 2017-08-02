#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	long a;
	cin>>a;
	long z[101]={0},x[a],t,m=0;
	for(long i=0;i<a;i++){
		cin>>t;
		z[t]++;
		if(t>m)
			m=t;
	}
	for(int i=0,j=0;i<101&&i<=m;i++){
		while(z[i]){
			x[j]=i;
			z[i]--;
			j++;
		}
	}
	if(a%2){
		cout<<fixed<<setprecision(1)<<float(x[a/2])<<endl;
	}
	else{
		float h =(float) (x[a/2]+x[a/2-1])/2;
		cout<<fixed<<setprecision(1)<<h<<endl;
	}
	return 0;
}
