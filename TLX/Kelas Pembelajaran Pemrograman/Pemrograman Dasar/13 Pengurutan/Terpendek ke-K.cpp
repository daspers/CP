#include <iostream>

using namespace std;

int main(){
	int a, b,in;
	cin>>a>>b;
	long c[a],t;
	for(int i=0;i<a;i++){
		cin>>c[i];
	}
	for(int i=0;i<a-1;i++){
		in=i;
		for(int j=i+1;j<a;j++){
			if(c[in]>c[j])
				in=j;
		}
		if(in!=i){
			t=c[i];
			c[i]=c[in];
			c[in]=t;
		}
	}
	cout<<c[b-1]<<endl;
	return 0;
}
