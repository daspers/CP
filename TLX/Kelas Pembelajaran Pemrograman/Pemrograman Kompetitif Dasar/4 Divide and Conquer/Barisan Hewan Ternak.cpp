#include <bits/stdc++.h>
using namespace std;

long i, n, t, q, x[100005], l ,r, mid;

int main(){
	scanf("%ld", &n);
	scanf("%ld", x);
	for(i=1;i<n;i++){
		scanf("%ld", x+i);
		x[i]+=x[i-1];
	}
	scanf("%ld", &q);
	while(q--){
		scanf("%ld", &t);
		l = 0; r = n-1;
		mid = (l+r)/2;
		while(!(x[mid] >= t && x[mid-1]<t) && l<r){
			if(x[mid-1]<t)
				l = mid+1;
			else
				r = mid-1;
			mid = (l+r)/2;
		}
		printf("%ld\n", mid+1);
	}
	return 0;
}
