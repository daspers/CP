#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,t,j,i,k,m;
int a[100002], c;

bool cek(int v){
	int awal = 0;
	int temp = c-1;
	while(temp){
		int id = lower_bound(a+awal, a+n, a[awal]+v)-a;
		if(id == n)
			break;
		awal = id;
		temp--;
	}
	return temp ==0;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &c);
		for(i=0;i<n;i++){
			scanf("%d", a+i);
		}
		sort(a, a+n);
		int l = 1;
		int r = (a[n-1] - a[0])/(c-1);
		int mid = (l+r)>>1;
		while(l<r){
			if(cek(mid))
				l = mid;
			else
				r = mid-1;
			mid = (l+r+1)>>1;
		}
		printf("%d\n", l);
	}
	return 0;
}
