#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>

typedef long long ll;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,t,i,j,k,m;
ll a[1000002];

ll neg(ll x){
	ll ten = 1;
	ll ans = 0;
	do{
		ans += ten*(9 - (x%10));
		ten *=10;
		x /=10;
	}while(x);
	return ans;
}

ll add(ll a,ll b){
	ll ten = 1;
	ll ans = 0;
	while(a || b){
		ans += ten*(((a%10) + (b%10)) %10);
		ten *=10;
		a/=10;
		b/=10;
	}
	return ans;
}

int main(){
	scanf("%d", &n);
	for(i=0;i<n;i++)
		scanf("%lld", a+i);
	sort(a, a+n);
	ll mi = add(a[0], a[1]);
	ll ma = add(a[0], a[n-1]);
	for(i=0;i<n;i++){
		ll na = neg(a[i]);
		int idx = upper_bound(a, a+n, na) - a;
		// cout<<i<<" "<<idx<<" "<<ma<<endl;
		if(idx-1>=0 && (idx-1)!=i){
			ll tmp = add(a[i], a[idx-1]);
			if(tmp < mi)
				mi = tmp;
			if(tmp > ma)
				ma = tmp;
		}
		if(idx<n && idx !=i){
			ll tmp = add(a[i], a[idx]);
			if(tmp < mi)
				mi = tmp;
			if(tmp > ma)
				ma = tmp;
		}
	}
	printf("%lld %lld\n", mi, ma);
	return 0;
}