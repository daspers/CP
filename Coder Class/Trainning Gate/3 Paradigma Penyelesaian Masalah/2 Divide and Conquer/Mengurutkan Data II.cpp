#include <iostream>
#include <stdio.h>

using namespace std;

void mergesort(long *b, long a, long l, long r){
	if(l==r){
		return;
	}
	else{
		long mid = (r+l)/2,t1,i,j,s;
		mergesort(b,a,l,mid);
		mergesort(b,a,mid+1,r);
		s=r-l+1;
		long t2[s], k=0;
		for(i=l,j=mid+1;i<=mid&&j<=r;k++){
			if(b[i]>b[j]){
				t2[k]=b[j];
				j++;
			}
			else{
				t2[k]=b[i];
				i++;
			}
		}
		while(j<=r){
			t2[k]=b[j];
			k++,j++;
		}
		while(i<=mid){
			t2[k]=b[i];
			k++,i++;
		}
		for(k=0, i=l;i<=r&&k<s;i++,k++){
			b[i]=t2[k];
		}
	}
}

int main(){
	long a;
	scanf("%ld", &a);
	long *b=new long[a];
	for(int i=0;i<a;i++){
		scanf("%ld", &b[i]);
	}
	mergesort(b,a,0,a-1);
	for(int i=0;i<a;i++){
		printf("%ld", b[i]);
		if(i<a-1)
			printf(" ");
	}
	printf("\n");
	return 0;
}
