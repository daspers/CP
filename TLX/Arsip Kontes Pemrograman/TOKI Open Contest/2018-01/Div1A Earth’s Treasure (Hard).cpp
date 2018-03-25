#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;

const ll mod = 1e9+7;

int n, i, j, k, t,l,r,mid;
int a,b,c,d;
pair<int, int> tem ;

int main(){
	scanf("%d", &n);
	if(n==1){
		puts("0 0");
		return 0;
	}
	l = 1;
	r = 22361;
	mid = (l+r)/2;
	while(l<r){
		if(2*mid*mid+2*mid+1<n)
			l = mid+1;
		else if(2*mid*mid-2*mid+2>n)
			r = mid-1;
		else
			break;
		mid = (l+r)/2;
	}
	a = 2*mid*mid-2*mid+2;
	b = 2*mid*mid+1;
	c = 2*mid*mid+mid+1;
	d = 2*mid*mid+2*mid+1;
	if(a==n)
		printf("-%d 0\n", mid);
	else if(b==n)
		printf("0 %d\n", mid);
	else if(c==n)
		printf("%d 0\n", mid);
	else if(d==n)
		printf("0 -%d\n", mid);
	else{
		if(n>b&&n<c){
			t = n-b;
			printf("%d %d\n", t, mid-t);
		}
		else if(n>c&&n<d){
			t = n-c;
			printf("%d -%d\n", mid-t, t);
		}
		else{
			t = n-a+1;
			t/=2;
			if(n&1)
				printf("-%d %d\n", mid-t, t);
			else
				printf("-%d -%d\n", mid-t, t);
		}
	}
	return 0;
}
