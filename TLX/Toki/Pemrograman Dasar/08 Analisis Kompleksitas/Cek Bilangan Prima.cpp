#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int pc(long a){
	for(long i=2;i<=sqrt(a);i++){
		if(a%i<1) return 0;
	}
	return a<2?0:1;
}

int main(){
	vector<long> d;
	int k;
	cin>>k;
	long x;
	while(k--){
		cin>>x;
		d.push_back(x);
	}
	for(int i=0;i<d.size();i++){
		if(pc(d[i])) cout<< "YA";
		else cout<<"BUKAN";
		cout<<endl;
	}
	return 0;
}
