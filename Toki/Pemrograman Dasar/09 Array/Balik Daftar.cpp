#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<long> x;
	long y;
	while(cin>>y) x.push_back(y);
	for(int i=x.size()-1;i>=0;i--) cout<<x[i]<<endl;
	return 0;
}
