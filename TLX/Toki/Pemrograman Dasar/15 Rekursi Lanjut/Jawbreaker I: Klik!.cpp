#include <iostream>

using namespace std;

long h=0;

void get(int **a, int b, int c, int x, int y, int n, bool **s){
	if(s[x][y])
		return;
	else if(a[x][y]==n){
		s[x][y]=true;
		h++;
		if(x>0)
			get(a,b,c,x-1,y,n,s);
		if(y>0)
			get(a,b,c,x,y-1,n,s);
		if(x<b-1)
			get(a,b,c,x+1,y,n,s);
		if(y<c-1)
			get(a,b,c,x,y+1,n,s);
	}
}

int main(){
	int **a, b, c,x,y;
	bool **s;
	cin>>b>>c;
	a= new int*[b];
	s=new bool*[b];
	for(int i=0;i<b;i++){
		a[i]=new int [c];
		s[i]=new bool [c];
		for(int j=0;j<c;j++){
			cin>>a[i][j];
			s[i][j]=false;
		}
	}
	cin>>x>>y;
	get(a,b,c,x,y,a[x][y],s);
	cout<<h*(h-1)<<endl;
	delete[] a;
	return 0;
}
