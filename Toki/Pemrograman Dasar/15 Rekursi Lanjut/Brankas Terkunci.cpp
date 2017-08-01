#include <iostream>
#include <iomanip>

using namespace std;

int n;
int *x;
bool y[10]={false};

void per(int a, int b){
	if(a>=n||b==0){
		for(int i=0;i<a;i++){
			cout<<x[i];
			if(i<a-1)
				cout<<" ";
		}
		cout<<endl;
	}
	else{
		for(int i=0;i<n;i++){
			if(!y[i+1]){
				if(a==0){
					y[i+1]=true;
					x[a]=i+1;
					per(a+1,b-1);
					y[i+1]=false;
				}
				else if(i+1>x[a-1]){
					y[i+1]=true;
					x[a]=i+1;
					per(a+1,b-1);
					y[i+1]=false;
				}
			}
		}
	}
}

int main(){
	int m;
	cin>>n>>m;
	x= new int[n];
	per(0,m);
	return 0;
}
