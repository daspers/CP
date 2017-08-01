#include <iostream>
#include <string>

using namespace std;

bool pp(string x, long a){
	if(a==1 || a==0)
		return true;
	if(x[0]!=x[a-1])
		return false;
	else{
		for(int i=0;i<a-1;i++){
			x[i]=x[i+1];
		}
		return pp(x,a-2);
	}
}

int main(){
	string x;
	cin>>x;
	if(pp(x, x.size()))
		cout<<"YA\n";
	else
		cout<<"BUKAN\n";
	return 0;
}
