#include <iostream>
#include <iomanip>

using namespace std;

int n;
int *x;
bool y[10]={false};

void per(int a, int b, int c){
	if(a>=n){
		for(int i=0;i<a;i++)
			cout<<x[i];
		cout<<endl;
	}
	else{
		for(int i=0;i<n;i++){
			if(!y[i+1]){
				if(b==0&&c==0){
					y[i+1]=true;
					x[a]=i+1;
					per(a+1,c,x[a]);
					y[i+1]=false;
				}
				else if(b==0 && i+1!=c){
					y[i+1]=true;
					x[a]=i+1;
					per(a+1,c,x[a]);
					y[i+1]=false;
				}
				else if((c<b&&i+1>c)||(c>b&&i+1<c)){
					y[i+1]=true;
					x[a]=i+1;
					per(a+1,c,x[a]);
					y[i+1]=false;
				}
			}
		}
	}
}

int main(){
	cin>>n;
	x= new int[n];
	per(0,0,0);
	return 0;
}
