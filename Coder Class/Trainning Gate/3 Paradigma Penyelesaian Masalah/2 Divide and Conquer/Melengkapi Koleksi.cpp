#include <iostream>

using namespace std;

int main(){
	long a,b,t;
	cin>>a>>b;
	long c[a];
	for(long i=0;i<a;i++){
		cin>>c[i];
	}
	for(long i=0;i<b;i++){
		cin>>t;
		long mi=0, ma=a-1, mid;
		if(t==c[mi]||t==c[ma])
			cout<<"ada\n";
		else{
			mid=(ma+mi)/2;
			while(mi!=mid&&t!=c[mid]){
				if(t>c[mid]){
					mi=mid;
				}
				else{
					ma=mid;
				}
				mid=(mi+ma)/2;
			}
			if(t==c[mid]||t==c[ma])
				cout<<"ada\n";
			else
				cout<<"tidak ada\n";
		}
	}
	return 0;
}
