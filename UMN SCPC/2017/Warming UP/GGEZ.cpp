//Problem Simple Yet Complicated

#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	long a,b,c;
	scanf("%d",&t);
	
	for(int i=1;i<=t;i++){
		scanf("%ld %ld %ld", &a, &b, &c);
		printf("Case #%d: ",i);
		printf("%ld\n", b/c-a/c+(a%c?0:1));
	}
	return 0;
}
