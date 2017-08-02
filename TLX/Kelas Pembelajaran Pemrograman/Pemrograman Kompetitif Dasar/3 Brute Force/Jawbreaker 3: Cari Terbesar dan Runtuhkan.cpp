#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> h,m;
vector<int> t;
int hs,ms;

void collapse(char **a,int b,int c){
	for(int i=0;i<c;i++){
		int m,n;
		char t;
		for(m=b-1;m>=0&&a[m][i]!='.';m--);
		for(n=m-1;n>=0;n--){
			if(a[n][i]!='.'){
				a[m--][i]=a[n][i];
				a[n][i]='.';
			}
		}
		
	}
}

bool cek(int i, int j){
	for(int k=0;k<m.size();k++){
		if(i==m[k][0]&&j==m[k][1])
			return true;
	}
	return false;
}

void get(char **a, int b, int c, int x, int y, char n, bool **s){
	if(s[x][y])
		return;
	else if(a[x][y]==n){
		s[x][y]=true;
		t.clear();
		t.push_back(x);
		t.push_back(y);
		h.push_back(t);
		hs++;
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
	char **a;
	int b, c;
	bool **s;
	cin>>b>>c;
	a= new char*[b];
	s=new bool*[b];
	for(int i=0;i<b;i++){
		a[i]=new char [c];
		s[i]=new bool [c];
		for(int j=0;j<c;j++){
			cin>>a[i][j];
			s[i][j]=false;
		}
	}
	ms=0;
	for(int i=0;i<b;i++){
		for(int j=0;j<c;j++){
				hs=0;
				h.clear();
				get(a,b,c,i,j,a[i][j],s);
				if(hs>ms){
					m.clear();
					m=h;
					ms=hs;
				}
		}
	}
	for(int i=0;i<b;i++){
		for(int j=0;j<c;j++){
			if(cek(i,j))
				a[i][j]='.';
		}
	}
	collapse(a, b, c);
	for(int i=0;i<b;i++){
		for(int j=0;j<c;j++){
			cout<<a[i][j];
			if(j<c-1)
				cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}
