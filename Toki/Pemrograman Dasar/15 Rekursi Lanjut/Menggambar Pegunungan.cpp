#include <iostream>

using namespace std;

void draw(int a){
	if(a==1){
		cout<<"*"<<endl;
	}
	else{
		cout<<"*";
		draw(a-1);
		draw(a-1);
	}
}

int main(){
	int a;
	cin>>a;
	for(int i=1;i<=a;i++)
		draw(i);
	return 0;
}
