#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
 
const ll mod = 1e9+7;
const double pi = acos(-1);

ll n,j,i,k,m;
ll a[1000002];

ll hitung (ll h){
	ll sum = 0;
	for(int i=0;i<n;i++){
		if(a[i]>h)
			sum += a[i]-h;
	}
	return sum;
}

int main(){
	scanf("%lld %lld", &n, &m);
	for(i=0;i<n;i++){
		scanf("%lld", a+i);
	}
	ll l = 0;
	ll r = *max_element(a, a+n);
	ll mid = (l+r)>>1;
	while(l<r){
		if(hitung(mid)>=m)
			l = mid;
		else
			r = mid-1;
		mid = (l+r+1)>>1;
	}
	printf("%lld\n",l);
	return 0;
}