#include <iostream>
#include <string>
#include <vector>

using namespace std;


void change1(int **a,int b,int c, int d, int e){
	for(int i=b;i<d;i++){
		for(int j=c;j<e;j++){
			a[i][j]=1;
		}
	}
}

bool check(string *a, int b, string x){
	for(int i=0;i<b;i++){
		if(a[i]==x)
			return true;
	}
	return false;
}

void split(int **a, string *b, int c, int d, int e, int f, int g, string x){
	if(check(b,c,"1"+x)){
		change1(a, d, e, f, g);
	}
	else if(f-d<2||g-e<2){
		return;
	}
	else{
		int mid1=(d+f)/2,mid2=(e+g)/2;
		split(a, b, c, d, e, mid1, mid2, x+"0");
		split(a, b, c, d, mid2, mid1, g, x+"1");
		split(a, b, c, mid1, e, f, mid2, x+"2");
		split(a, b, c, mid1, mid2, f, g, x+"3");
	}
}


int main(){
	int a, c, d, z, **f;
	cin>>a;
	string *b;
	b=new string [a];
	for(int i=0;i<a;i++)
		cin>>b[i];
	cin>>c>>d;
	for(z=1; z<c||z<d;z*=2);
	f=new int *[z];
	for(int i=0;i<z;i++){
		f[i]=new int [z];
		for(int j=0;j<z;j++)
			f[i][j]=0;
	}
	split(f, b, a, 0, 0, z, z, "");
	for(int i=0;i<c;i++){
		for(int j=0;j<d;j++){
			cout<<f[i][j];
			if(j<d-1)
				cout<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
