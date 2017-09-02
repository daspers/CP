//Problem Prime Love

#include <bits/stdc++.h>

using namespace std;

int p[201]={0}, sz=1;

bool isprime(int a){
	int k=sqrt(a);
	for(int i=0;p[i]<=k;i++){
		if(a%p[i]==0)
			return false;
	}
	return true;
}

void genprime(){
	for(int i=3;i<=200;i+=2){
		if(isprime(i))
			p[sz++]=i;
	}
}

int main(){
	int t, a,b;
	scanf("%d",&t);
	genprime();
	for(int i=1;i<=t;i++){
		scanf("%d %d",&a, &b);
		printf("Case #%d: ",i);
		if(isprime(a+b))
			printf("Cocok\n");
		else
			printf("Tidak Cocok\n");
	}
	return 0;
}
  
