#include <bits/stdc++.h>

using namespace std;

int main(){
	int t,a;
	long b, c,d;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d %ld",&a,&b);
		c=0;
		for(int j=0;j<a;j++){
			scanf("%ld",&d);
			c+=d;
		}
		printf("Case #%d: ",i);
		if(c>b)
			printf("1\n");
		else if(b%c)
			printf("%ld\n", b/c+1);
		else
			printf("%ld\n", b/c);
	}
	return 0;
};
