#include <bits/stdc++.h>

using namespace std;

#define se second
#define fi first
#define mp make_pair

typedef long long int ll;

ll n, i, j, k, c,x,y;
pair<ll, ll> a[100005];

int main() {
    scanf("%lld %lld", &n, &k);
	for(i=0;i<n;i++){
		scanf("%lld %lld", &x, &y);
		a[i] = mp(x, y);
	}
	sort(a, a+n);
	for(c=i=0;i<n && k>=a[i].fi;i++){
		if(a[i].se < 1e10 && a[i].fi<1e10){
			if(k>=a[i].fi*a[i].se){
				k-=a[i].fi*a[i].se;
				c+=a[i].se;
			}
			else if(k>=a[i].fi){
				c+=k/a[i].fi;
				break;
			}
			else
				break;
		}
		else
			while(a[i].se && k>=a[i].fi){
				k-=a[i].fi;
				c++;
				a[i].se--;
			}
	}
	printf("%lld\n", c);
    return 0;
}
