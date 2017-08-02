#include <iostream>

using namespace std;

int main(){
	long a,b,x,y;
	cin>>a;
	long *c;
	c = new long [a];
	for(long i=0;i<a;i++){
		cin>>c[i];
	}
	cin>>b;
	for(long i=0;i<b;i++){
		cin>>x>>y;
		long mi=0, ma=a-1,mid;
		if(y<c[mi])
			cout<<"0\n";
		else if(x>=c[ma])
			cout<<"0\n";
		else if(y==c[mi]){
			mid=1;
			while(c[++mi]==y){
				mid++;
			}
			cout<<mid<<"\n";
		}
		else{
			mi=0, ma=a-1;
			long ix,iy;
			if(x<c[mi])
				ix = -1;
			else if(x==c[mi]){
				ix=0;
				while(x==c[++mi])
					ix++;
			}
			else{
				mid = (mi+ma)/2;
				while(mi!=mid && ma!=mid){
					if(c[mid]>x){
						if(c[mid-1] <= x){
							ix=mid-1;
							break;
						}
						else
							ma=mid;
					}
					else{
						mi=mid;
					}
					mid = (mi+ma)/2;
				}
				if(mid == mi || mid ==ma)
					ix=mid;
			}
			mi=0, ma=a-1;
			if(y>=c[ma]){
				iy=ma;
			}
			else{
				mid = (mi+ma)/2;
				while(mi!=mid && ma!=mid){
					if(c[mid+1]>y){
						if(c[mid]<=y){
							iy=mid;
							break;
						}
						else
							ma=mid;
					}
					else{
						mi=mid;
					}
					mid = (mi+ma)/2;
				}
				if(mid == mi || mid ==ma)
					iy=mid;
			}
			cout<<iy-ix<<"\n";
		}
	}
	delete[] c;
	return 0;
}
