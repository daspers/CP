#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define Nmax 300000

typedef long long ll;
typedef complex<double> cd;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t,m;
int a[100003];
int pr[30002], ne[30002];

int main(){
	memset(pr, 0, sizeof pr);
	memset(ne, 0, sizeof ne);
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d", a+i);
		ne[a[i]]++;
	}
	ne[a[0]]--;
	pr[a[0]]++;
	ll ans=0;
	for(i=1;i<n-1;i++){
		ne[a[i]]--;
		for(j=min(a[i]-1, 30000-a[i]);j>0;j--){
			ans += 1LL*ne[a[i]-j]*pr[a[i]+j];
			ans += 1LL*ne[a[i]+j]*pr[a[i]-j];
		}
		ans += 1LL*ne[a[i]]*pr[a[i]];
		pr[a[i]]++;
	}
	printf("%lld\n", ans);
	return 0;
}