//Problem Ledakan Terbesar

#include <bits/stdc++.h>

using namespace std;

bool r[50][50]={{true}};
string c[50]={""};
int a, b;

void check(int j, int k, int &coun){
	if(r[j][k]&&c[j][k]=='*'){
		coun++;
		r[j][k]=false;
		if(j>0)
			check(j-1,k,coun);
		if(k>0)
			check(j,k-1,coun);
		if(j<a-1)
			check(j+1,k,coun);
		if(k<b-1)
			check(j,k+1,coun);
	}
}

int main(){
	int t,ma=0,coun;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		ma=0;
		scanf("%d %d",&a, &b);
		for(int j=0;j<a;j++){
			cin>>c[j];
			for(int k=0;k<b;k++)
				r[j][k]=true;
		}
		for(int j=0;j<a;j++){
			for(int k=0;k<b;k++){
				if(r[j][k]&&c[j][k]=='*'){
					coun=0;
					check(j,k,coun);
					if(coun>ma)
						ma=coun;
				}
			}
		}
		printf("Case #%d: ",i);
		printf("%d\n",ma);
	}
	return 0;
}
