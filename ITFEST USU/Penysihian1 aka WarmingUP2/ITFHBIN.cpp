#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>

typedef long long ll;

int const mod = 1e9+7;

int n,i,j,k,t,r ;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		bitset<32> b(n);
		k=n;
		for(i=0;k;k>>=1)
			i++;
		for(j=0,k=i-1;j<k;j++,k--){
			if(b[j]!=b[k])
				b[j]=b[k]=1;
		}
		r = b.to_ulong();
		if(r==n)
			puts("PALINDROM");
		else
			printf("%d\n", r);
	}
}
