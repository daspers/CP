#include <iostream>
#include <math.h>

using namespace std;

int **a,**b,**t;

bool same(int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(t[i][j]!=b[i][j])
				return false;
		}
	}
	return true;
}

int main(){
	int n,m;
	cin>>n>>n;
	a=new int*[n];
	for(int i=0;i<n;i++){
		a[i]=new int [n];
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	}
	t=new int*[n];
	for(int i=0;i<n;i++){
		t[i]=new int [n];
	}
	cin>>m>>m;
	b=new int*[m];
	for(int i=0;i<m;i++){
		b[i]=new int [m];
		for(int j=0;j<n;j++)
			cin>>b[i][j];
	}
	//indentik
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			t[i][j]=a[i][j];
		}
	}
	if(same(n))
		cout<<"identik\n";
	else{
		//horizontal
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				t[n-i-1][j]=a[i][j];
			}
		}
		if(same(n))
			cout<<"horisontal\n";
		else{
			//vertical
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					t[i][n-j-1]=a[i][j];
				}
			}
			if(same(n))
				cout<<"vertikal\n";
			else{
				//diagonal kiri bawah
				for(int i=0;i<n;i++){
					for(int j=0;j<n;j++){
						t[n-j-1][n-i-1]=a[i][j];
					}
				}
				if(same(n))
					cout<<"diagonal kiri bawah\n";
				else{
					//diagonal kanan bawah
					for(int i=0;i<n;i++){
						for(int j=0;j<n;j++){
							t[j][i]=a[i][j];
						}
					}
					if(same(n))
						cout<<"diagonal kanan bawah\n";
					else
						cout<<"tidak identik\n";
				}
			}
		}
	}
	return 0;
}
