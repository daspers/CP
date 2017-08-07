#include <iostream>

using namespace std;

void mergesort(long **b, long l, long r){
	if(l!=r){
		long mid = (l+r)/2;
		mergesort(b,l,mid);
		mergesort(b,mid+1,r);
		long t[r-l+1][2],i,j,k;
		for(i=l,j=mid+1,k=0;i<=mid&&j<=r;k++){
			if(b[i][1]>b[j][1]){
				t[k][0]=b[j][0];
				t[k][1]=b[j][1];
				j++;
			}
			else if(b[i][1]==b[j][1]&&b[i][0]<b[j][0]){
				t[k][0]=b[j][0];
				t[k][1]=b[j][1];
				j++;
			}
			else{
				t[k][0]=b[i][0];
				t[k][1]=b[i][1];
				i++;
			}
		}
		while(i<=mid){
			t[k][0]=b[i][0];
			t[k][1]=b[i][1];
			i++;
			k++;
		}
		while(j<=r){
			t[k][0]=b[j][0];
			t[k][1]=b[j][1];
			j++;
			k++;
		}
		for(i=l, k=0;i<=r;k++,i++){
			b[i][0]=t[k][0];
			b[i][1]=t[k][1];
		}
	}
}

int main()
{
	long a,c=0,e=0;
	cin>>a;
	long **b=new long *[a];
	for(long i=0;i<a;i++){
		b[i]=new long [2];
		cin>>b[i][0]>>b[i][1];
	}
	mergesort(b,0,a-1);
	for(long i=0;i<a;i++){
		if(b[i][0]>e){
			c++;
			e=b[i][1];
		}
	}
	cout<<c<<endl;
	return 0;
}
