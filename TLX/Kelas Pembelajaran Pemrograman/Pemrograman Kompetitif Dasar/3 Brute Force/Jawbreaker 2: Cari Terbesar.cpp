#include <iostream>

using namespace std;

long h=0,m=0;

void makefalse(bool **s,int b,int c){
	for(int i=0;i<b;i++){
		for(int j=0;j<c;j++){
			s[i][j]=false;
		}
	}
}

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
	int **a, b, c;
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
	for(int i=0;i<b;i++){
		for(int j=0;j<c;j++){
			makefalse(s,b,c);
			get(a,b,c,i,j,a[i][j],s);
			if(h>m)
				m=h;
			h=0;
		}
	}
	cout<<m*(m-1)<<endl;
	return 0;
}
