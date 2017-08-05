#include <iostream>
#include <math.h>
#include <algorithm>

#define cTOt(a,b) t[(a)][0]=c[(b)][0],t[(a)][1]=c[(b)][1];

using namespace std;

void mergesort(uint64_t **c, long l, long r){
	if(l!=r){
		long mid=(l+r)/2;
		mergesort(c,l,mid);
		mergesort(c,mid+1,r);
		long i, j,k,t[r-l+1][2];
		for(i=l,j=mid+1, k=0;i<=mid&&j<=r;k++){
			if(c[i][0]>c[j][0]){
				cTOt(k,j)
				j++;
			}
			else if(c[i][0]==c[j][0]&&c[i][1]<c[j][1]){
				cTOt(k,j)
				j++;
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
	uint64_t a,b, n=0, e=0;
	cin>>a>>b;
	uint64_t **c=new uint64_t *[a];
	for(long i=0;i<a;i++){
		c[i]=new uint64_t [2];
		cin>>c[i][0]>>c[i][1];
	}
	//sort
	mergesort(c,0,a-1);
	if(c[0][0]>1)
		cout<<-1<<"\n";
	else{
		for(uint64_t i=0,j,k;i<a&&e<b;){
			if(c[i][1]>e){
				n++;
				k=i,j=i;
				while(j<a&&c[j][0]<=e+1){
					if(c[j][0]!=c[k][0]){
						if(c[j][1]>c[k][1]){
							k=j;
						}
					}
					j++;
				}
				i=k;
				e=c[i][1];
			}
			else
				i++;
		}
		if(e<b)
			cout<<-1<<"\n";
		else
			cout<<n<<endl;
	}
	return 0;
}
