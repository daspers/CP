#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-8
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
int a[100002];

bool coba(int val){
	int now = 0;
	int cnt = 1;
	while(now < n){
		int idx = lower_bound(a, a+n, a[now] + val)-a;
		if(idx <= now)
			idx = now+1;
		if(idx >= n)
			break;
		now = idx;
		cnt++;
	}
	// cout<<val<<" "<<cnt<<endl;
	return cnt >= k;
}

int main(){
	scanf("%d %d", &n, &k);
	for(i=0;i<n;++i)
		scanf("%d", a+i);
	sort(a, a+n);
	int l = 0, r = a[n-1]-a[0];
	while(l < r){
		int mid = (l+r+1)/2;
		if(coba(mid))
			l = mid;
		else
			r = mid-1;
	}
	printf("%d\n", l);
	return 0;
}