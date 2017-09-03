#include <bits/stdc++.h>

using namespace std;

int main(){
	long t,a,b,c,f;
	double d,e;
	scanf("%ld",&t);
	for(int i=1;i<=t;i++){
		scanf("%ld %ld %ld",&a, &b, &c);
		printf("Case #%d: ",i);
		if(a>=b)
			printf("0\n");
		else{
			d=(double)b/a;
			e=(double)1+c/100.0;
			f=ceil(log(d)/log(e));
			printf("%ld\n",f );
		}
	}
	return 0;
}
