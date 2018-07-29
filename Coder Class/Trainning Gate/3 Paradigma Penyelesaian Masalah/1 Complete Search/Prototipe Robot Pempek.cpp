#include <iostream>
#include <math.h>
#include <string>

using namespace std;

struct point{
	int x;
	int y;
};

int main(){
	int a,b,c,d,m=0;
	cin>>a>>b>>c>>d;
	point x[c];
	string p[a];
	for(int i =0;i<a;i++){
		cin>>p[i];
		for(int j=0;j<b;j++){
			if(p[i][j]=='X'){
				x[m].x=i;
				x[m].y=j;
				m++;
			}
		}
	}
	for(int i=0;i<d;i++){
		int r,s,min=a+b,t;
		cin>>r>>s;
		for(int j=0;j<c;j++){
			t=abs(x[j].x-r+1)+abs(x[j].y-s+1);
			if(t<min)
				min=t;
		}
		cout<<min<<"\n";
	}
	return 0;
}
