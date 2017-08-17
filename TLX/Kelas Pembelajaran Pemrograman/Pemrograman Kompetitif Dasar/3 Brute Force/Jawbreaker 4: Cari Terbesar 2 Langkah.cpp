#include <iostream>

using namespace std;

void assign(int **c, int **e, int a, int b){
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			e[i][j]=c[i][j];
		}
	}
}

void find(int **e, int a, int b, int i, int j, int n, int &count){
	if(e[i][j]==n){
		count++;
		e[i][j]=0;
		if(i>0)
			find(e,a,b,i-1,j,n,count);
		if(j>0)
			find(e,a,b,i,j-1,n,count);
		if(i<a-1)
			find(e,a,b,i+1,j,n,count);
		if(j<b-1)
			find(e,a,b,i,j+1,n,count);
	}
}

void collapse(int **e, int a, int b){
	int m,i,j,k;
	for(i=b-1;i>=0;i--){
		j=a-1;
		if(e[j][i]>0){
			while(j>0&&e[j-1][i]>0)
			j--;
			j--;
		}
		for(k=j-1;k>=0;k--){
			if(e[k][i]>0){
				m=e[k][i];
				e[k][i]=e[j][i];
				e[j][i]=m;
				j--;
			}
		}
	}
}

int main(){
	int a, b, ma=0, count, mt,m;
	cin>>a>>b;
	int **c=new int *[a],**e=new int *[a], **d=new int *[a];
	for(int i=0;i<a;i++){
		c[i]=new int [b];
		e[i]=new int [b];
		d[i]=new int [b];
		for(int j=0;j<b;j++){
			cin>>c[i][j];
		}
	}
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			assign(c,e,a,b);
			count=0;
			find(e,a,b,i,j,e[i][j],count);
			mt=count*(count-1);
			collapse(e,a,b);
			m=0;
			for(int k=0;k<a;k++){
				for(int l=0;l<b;l++){
					if(e[k][l]>0){
						count=0;
						find(e,a,b,k,l,e[k][l],count);
						if(count>m)
							m=count;
					}
				}
			}
			mt+=m*(m-1);
			if(mt>ma)
				ma=mt;
		}
	}
	cout<<ma<<endl;
	return 0;
}
