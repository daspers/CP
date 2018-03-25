#include <bits/stdc++.h>

using namespace std;

int t,n,k;

int main(){
	FILE *F;
	F = fopen("tabs.in", "r");
    fscanf(F,"%d", &t);
	while(t--){
		fscanf(F,"%d %d",&n, &k);
		if(n==1 &&k==1)
			puts("0");
		else if(k==1 || n==k)
			puts("1");
		else
			puts("2");
	}
    return 0;
}