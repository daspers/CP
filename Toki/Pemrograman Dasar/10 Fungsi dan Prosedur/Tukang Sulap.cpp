#include <iostream>

using namespace std;

int main(){
	long a, o, m, n;
	char c,d;
	cin >>a;
	int b[2][a];
	for(int i=0;i<2;i++){
		for(int j=0;j<a;j++){
			cin>>b[i][j];
		}
	}
	cin>>o;
	for(int i=0;i<o;i++){
		cin>>c>>m>>d>>n;
		if(c == 'A'){
			if(d=='B'){
				long k = b[0][m-1];
				b[0][m-1]=b[1][n-1];
				b[1][n-1]=k;
			}
			else{
				long k = b[0][m-1];
				b[0][m-1]=b[0][n-1];
				b[0][n-1]=k;
			}
		}
		else{
			if(d=='B'){
				long k = b[1][m-1];
				b[1][m-1]=b[1][n-1];
				b[1][n-1]=k;
			}
			else{
				long k = b[1][m-1];
				b[1][m-1]=b[0][n-1];
				b[0][n-1]=k;
			}
		}
	}
	for(int i=0;i<2;i++){
		for(int j=0;j<a;j++){
			cout << b[i][j];
			if(j<a-1) cout << " ";
		}
		cout<< endl;
	}
	return 0;
}
