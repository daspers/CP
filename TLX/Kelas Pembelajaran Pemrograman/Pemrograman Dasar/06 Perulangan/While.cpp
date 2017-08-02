#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	vector<string> x;
	string y;
	while(cin>>y){
		x.push_back(y);
	}
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<endl;
	}
	return 0;
}
