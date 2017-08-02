#include <iostream>

using namespace std;

int main(){
	int x;
	cin >>x;
	int a[x];
	for(int i=0;i<x;i++){
		cin>>a[i];
	}
	int m=a[0], n=a[0];
	for(int i=0;i<x;i++){
		if (a[i]>m)
      			m=a[i];
		if(a[i]<n)
      			n=a[i];
	}
	cout<<m<<" "<<n<<endl;
	return 0;
}
