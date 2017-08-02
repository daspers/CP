#include <iostream>
#include <math.h>

using namespace std;

int pc(long a){
	int k=0;
	for(long i=2;i<=sqrt(a);i++){
		if(a%i<1) k++;
		if(k>1) return 0;
	}
	return 1;
}

int main(){
	int k;
	cin>>k;
	long d[k];
	for(int i=0;i<k;i++){
		cin>>d[i];
	}
	for(int i=0;i<k;i++){
		if(pc(d[i])) cout<< "YA";
		else cout<<"BUKAN";
		cout<<endl;
	}
	return 0;
}
