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

int n,i,j,k,t;
int a[200002];
int b[200002], c[200002];

bool cek(int x){
	int now=0;
	for(int i=0;i<n;i++){
		if(x){
			if(a[i]>now)
				x--;
			now++;
		}
		else if(a[i]<= now)
			now ++;
	}
	return (now >= k);
}

int main(){
	scanf("%d %d", &n, &k);
	for(i=0;i<n;i++)
		scanf("%d", a+i);
	int l = 0;
	int r = k;
	while(l<r){
		int mid = (l+r)>>1;
		if(cek(mid)){
			r = mid;
		}
		else{
			l = mid+1;
		}
	}
	printf("%d\n", r);
	return 0;
}