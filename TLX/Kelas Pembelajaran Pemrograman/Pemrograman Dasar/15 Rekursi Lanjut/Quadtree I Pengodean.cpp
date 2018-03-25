#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> k;

bool full0(int **a,int b,int c, int d, int e){
	for(int i=b;i<d;i++){
		for(int j=c;j<e;j++){
			if(a[i][j]==1)
				return false;
		}
	}
	return true;
}

bool full1(int **a,int b,int c, int d, int e){
	for(int i=b;i<d;i++){
		for(int j=c;j<e;j++){
			if(a[i][j]==0)
				return false;
		}
	}
	return true;
}

void split(int **a, int b, int c, int d, int e, string x){
	if(full0(a,b,c,d,e)){
		return;
	}
	else if(full1(a,b,c,d,e)){
		x="1"+x;
		k.push_back(stoi(x));
	}
	else{
		int mid1=(b+d)/2,mid2=(c+e)/2;
		split(a, b, c, mid1, mid2, x+"0");
		split(a, b, mid2, mid1, e, x+"1");
		split(a, mid1, c, d, mid2, x+"2");
		split(a, mid1, mid2, d, e, x+"3");
	}
}

int main(){
	int **a, b,c,z;
	cin>>b>>c;
	for(z=1; z<b||z<c;z*=2);
	a=new int*[z];
	for(int i=0;i<z;i++){
		a[i]=new int [z];
		for(int j=0;j<z;j++){
			if(i<b&&j<c)
				cin>>a[i][j];
			else
				a[i][j]=0;
		}
	}
	split(a,0,0,z,z,"");
	cout<<k.size()<<endl;
	for(int i=0;i<k.size();i++)
		cout<<k[i]<<endl;
	return 0;
}