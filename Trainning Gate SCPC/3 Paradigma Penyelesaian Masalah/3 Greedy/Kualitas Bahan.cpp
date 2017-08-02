#include <iostream>

#define cTOt(a,b) t[(a)][0]=c[(b)][0],t[(a)][1]=c[(b)][1];

using namespace std;

void mergesort(long **c, long l, long r){
	if(l!=r){
		long mid=(l+r)/2;
		mergesort(c,l,mid);
		mergesort(c,mid+1,r);
		long i, j,k,t[r-l+1][2];
		for(i=l,j=mid+1, k=0;i<=mid&&j<=r;k++){
			if(c[i][1]<c[j][1]){
				cTOt(k,j)
				j++;
			}
			else if(c[i][1]==c[j][1]){
				if(c[i][0]<c[j][0]){
					cTOt(k,j)
					j++;
				}
				else{
					cTOt(k,i)
					i++;
				}
			}
			else{
				cTOt(k,i)
				i++;
			}
		}
		while(i<=mid){
			cTOt(k,i)
			i++,k++;
		}
		while(j<=r){
			cTOt(k,j)
			j++,k++;
		}
		for(i=l,k=0;i<=r;i++,k++){
			c[i][0]=t[k][0];
			c[i][1]=t[k][1];
		}
	}
}

int main(){
	long a,y=0;
	cin>>a;
	long **c=new long *[a];
	for(long i=0;i<a;i++){
		c[i] = new long [2];
		cin>>c[i][0];
	}
	for(long i=0;i<a;i++){
		cin>>c[i][1];
	}
	//sort
	mergesort(c,0,a-1);
	for(long i=0;i<a;i++){
		y+=c[i][0]-i*c[i][1];
	}
	cout<<y<<"\n";
	return 0;
}
