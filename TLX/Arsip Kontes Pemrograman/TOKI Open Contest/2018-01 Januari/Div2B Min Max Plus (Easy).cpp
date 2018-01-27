
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;

ll n, i, j, k, t, q;
ll a,p,l,r,v;

int main(){
	scanf("%lld %lld %lld", &n, &q, &k);
	a=0;
	while(q--){
		scanf("%lld %lld %lld %lld", &p, &l, &r, &v);
		if(l<=k&&r>=k){
			if(p==1)
				a+=v;
			else if(p==2)
				a = max(a, v);
			else
				a = min(a, v);
		}
	}
	printf("%lld\n", a);
	return 0;
}
