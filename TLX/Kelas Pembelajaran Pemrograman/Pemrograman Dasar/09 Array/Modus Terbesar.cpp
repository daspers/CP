#include <iostream>

using namespace std;

int main(){
	int a,b;
	cin>>a;
	int x[1001]={0};
	for(int i=0;i<a;i++){
		cin>>b;
		x[b]++;
	}
	int n=0,l=0;
	for(int i=1000;i>0;i--){
		if(x[i]) if(x[i]>l) {l=x[i]; n=i;}
	}
	cout<<n<<endl;
	return 0;
}
