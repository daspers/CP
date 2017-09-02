//Problem Hero

#include <bits/stdc++.h>

using namespace std;

int main(){
	int t, a;
	long p[5000],b[5000];
	bool f;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&a);
		for(int j=0;j<a;j++)
			scanf("%ld",&p[j]);
		for(int j=0;j<a;j++)
			scanf("%ld",&b[j]);
		sort(p,p+a,greater<long>());
		f=false;
		for(int j=0;j<a&&!f;j++){
			if(b[j]>p[j])
				f=true;
			else if(j<a-1)
				p[j+1]+=p[j]-b[j];
		}
		printf("Case #%d: ",i);
		if(f)
			printf("IMPOSSIBLE\n");
		else
			printf("Yes he made it\n");
	}
	return 0;
}
