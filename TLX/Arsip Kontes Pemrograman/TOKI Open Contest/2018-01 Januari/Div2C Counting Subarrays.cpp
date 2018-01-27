
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;

const ll mod = 1e9+7;

ll n, i, j, k, t, q;
ll a[100002],p[100002];

int main(){
	for(i=0;i<=1e5;i++){
		p[i] = i*(i+1)/2;
		p[i] %= mod;
	}
	scanf("%lld %lld", &n, &q);
	for(i=0;i<q;i++)
		scanf("%lld", a+i);
	sort(a,a+q);
	t = p[n];
	for(i=1;i<q;i++){
		t -= p[a[i]-a[i-1]-1];
		t%=mod;
	}
	if(a[0]>1){
		t -= p[a[0]-1];
		t%=mod;
	}
	if(a[q-1]<n){
		t -= p[n-a[q-1]];
		t%=mod;
	}
	if(t<0)
		t+=mod;
	printf("%lld\n", t);
	return 0;
}
