#include <bits/stdc++.h>
 
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;

 
const ll mod = 1e9+7;

int n,t,i,j,k;
int m;
int a[1000005];
int wew[105];

bool cek(int len){
	memset(wew, 0, sizeof wew);
	for(int i=0;i<len-1;i++){
		if(a[i]<=k)
			wew[a[i]]++;
	}
	for(int i=len-1;i<n;i++){
		if(a[i] <= k)
			wew[a[i]]++;
		if(find(wew+1, wew+k+1, 0) == wew+k+1)
			return true;
		if(a[i-len+1] <= k)
			wew[a[i-len+1]]--;
	}
	return false;
}

int main(){
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	scanf("%d", &t);
	for(int cc=1;t--;cc++){
		printf("Case %d: ", cc);
		scanf("%d %d %d", &n, &m, &k);
		if(k>max(m, 3) || k> n){
			printf("sequence nai\n");
			continue;
		}
		if(k<=3){
			printf("%d\n", k);
			continue;
		}
		for(i=3;i<n;i++){
			a[i] = (a[i-1]+a[i-2]+a[i-3])%m+1;
		}
		int l = k;
		int r = n;
		while(l<r){
			int mid = (l+r)>>1;
			if(cek(mid))
				r = mid;
			else
				l = mid+1;
		}
		if(cek(r))
			printf("%d\n", r);
		else
			printf("sequence nai\n");
	}
	return 0;
}