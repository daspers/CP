#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;

int n,i,j,k,m,t;
ll a,b,c,d;

int main(){
	scanf("%lld %lld", &a, &b);
	c = a*b/9;
	d = (a*b)%9;
	printf("%lld.", c);
	for(i=0;i<11;i++)
		printf("%lld", d);
	puts("");
	return 0;
}
