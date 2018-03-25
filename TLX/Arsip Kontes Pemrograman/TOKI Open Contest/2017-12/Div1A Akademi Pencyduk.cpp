#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;

int n,i,j,k,m,p;
int a,b,c,d;

int main(){
	scanf("%d %d", &n, &m);
	scanf("%d %d", &a, &b);
	scanf("%d %d", &c, &d);
	//horizontal
	if(a==c&&b==d)
		k=0;
	else if(a==c){
		if(b<d)
			k = m-b+1;
		else
			k = b;
	}
	// vertical
	else if(b==d){
		if(a<c)
			k = n-a+1;
		else
			k = a;
	}
	//diagonal
	else if(a>c&&b>d)
		k = max(a, b);
	else if(a>c&&b<d)
		k = max(a, m-b+1);
	else if(a<c&&b<d)
		k = max(n-a+1, m-b+1);
	else if(a<c&&b>d)
		k = max(n-a+1, b);
	printf("%d\n",k);
	return 0;
}
