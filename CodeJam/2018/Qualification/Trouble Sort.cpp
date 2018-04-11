#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef unsigned long long ull;
 
const ll mod = 1e9+7;
const double pi = acos(-1);

int n,t,j,i,k;
int a[100002];

bool troublesort(){
	bool res= false;
	for(int i=0;i<n-2;i++){
		if(a[i]>a[i+2]){
			reverse(a+i, a+i+3);
			res = true;
		}
	}
	return res;
}

int main(){
	scanf("%d", &t);
	for(int cc=1;t--;cc++){
		scanf("%d", &n);
		for(i=0;i<n;i++)
			scanf("%d", a+i);
		while(troublesort());
		int cek = -1;
		for(int i=0;i<n-1;i++){
			if(a[i]>a[i+1]){
				cek = i;
				break;
			}
		}
		printf("Case #%d: ", cc);
		if(cek==-1)
			puts("OK");
		else
			printf("%d\n", cek);
	}
	return 0;
}