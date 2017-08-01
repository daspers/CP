#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

uint64_t x[50]={0}, c= 1e9+7, s;
vector<uint64_t> m;
bool n[31]={false};


uint64_t pow2(uint64_t a){
	if(a==0)
		return 2;
	if(x[a]==0){
		if(x[a-1]==0)
			x[a-1]=pow2(a-1);
		x[a]=(x[a-1]*x[a-1])%c;	
	}
	return x[a];
}

int main(){
	uint64_t a,b,i=30;
	cin>>a;
	for(int i=0;i<31;i++){
		m.push_back(pow(2, i));
	}
	b=a;
	while(b&&i>=0){
		if(b>=m[i]){
			b-=m[i];
			n[i]=true;
			//cout<<i<<endl;
		}
		i--;
	}
	b=1;
	for(int i=0;i<31;i++){
		if(n[i]){
			b*=pow2(i);
			b%=c;
		}
	}
	cout<<(b-1)%c<<"\n";
	return 0;
}
