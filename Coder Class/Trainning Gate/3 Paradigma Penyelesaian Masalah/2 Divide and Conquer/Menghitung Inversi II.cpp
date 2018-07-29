#include <iostream>

using namespace std;

void mergesort(long *b, long *t, long l, long r, long long &c){
	if(l!=r){
		long mid=(l+r)/2, i, j, k;
		mergesort(b, t, l, mid, c);
		mergesort(b, t, mid+1, r, c);
		bool w= true;
		for(i=l, j=mid+1, k=0;i<=mid&&j<=r;k++){
			if(b[i]>b[j]){
				t[k]=b[j];
				j++;
				if(w){
					w=false;
					c+=j-mid-1;
				}
				else{
					c++;
				}
			}
			else{
				t[k]=b[i];
				i++;
				if(w){
					c+=j-mid-1;
				}
				else{
					w=true;
				}
			}
		}
		if(i<mid){
			c+=(mid-i)*(r-mid);
		}
		while(i<=mid){
			t[k]=b[i];
			k++,i++;
		}
		while(j<=r){
			t[k]=b[j];
			k++,j++;
		}
		for(i=l, k=0;i<=r;i++,k++){
			b[i]=t[k];
		}
	}
}

int main(){
	long a;
	long long c=0;
	cin>>a;
	long *b=new long [a], *t=new long [a];
	for(long i=0;i<a;i++){
		cin>>b[i];
	}
	mergesort(b, t, 0, a-1, c);
	cout<<c<<endl;
	return 0;
}
