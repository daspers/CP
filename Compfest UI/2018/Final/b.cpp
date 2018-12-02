#include<bits/stdc++.h>

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
bool isp[300002];
vector<int> v[300002], prime;
pii a[300002];
int ans[300002];

int main(){
	memset(isp, true, sizeof isp);
	for(i=2;i<=300000;++i){
		if(isp[i]){
			prime.pb(i);
			for(ll j=i*i;j<=300000;j+=i)
				isp[j] = false;
		}
	}
	for(i=1;i<=300000;++i){
		int sq = sqrt(i);
		int tmp = i;
		for(j=0;tmp>1 && prime[j] <= sq;++j){
			if(tmp%prime[j]==0){
				int now = 1;
				do{
					now *= prime[j];
					tmp /= prime[j];
				}while(tmp%prime[j]==0);
				v[i].pb(now);
			}
		}
		if(tmp > 1)
			v[i].pb(tmp);
	}
	i=j=2;
	ans[1] = 0;
	while(j <= 300000){
		bool bisa = i<j;
		for(k=0;k<v[i].size();++k){
			if(j-i < v[i][k]){
				bisa = false;
				break;
			}
		}
		if(bisa)
			++i;
		else{
			ans[j] = i-1;
			++j;
		}
	}
	for(i=1;i<=300000;++i)
		a[i] = {ans[i], i};
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%d\n", lower_bound(a, a+300000, make_pair(n, 0))->se);
	}
	return 0;
}