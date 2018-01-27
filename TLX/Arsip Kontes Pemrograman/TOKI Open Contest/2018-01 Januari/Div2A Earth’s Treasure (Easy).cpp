#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

int n, i, j, k, t;
int x,y;

int main(){
	scanf("%d", &n);
	t = n-1;
	x=y=0;
	k =  ceil(t/4.0);
	if(t%4==1)
		x = -k;
	else if(t%4==2)
		y = k;
	else if(t%4==3)
		x = k;
	else
		y = -k;
	printf("%d %d\n", x, y);
	return 0;
}
