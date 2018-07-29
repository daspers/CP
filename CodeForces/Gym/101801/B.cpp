#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-9
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"

typedef long long ll;
typedef complex<double> cd;
typedef pair<int, int> pii;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
int a[100005];
vector<int> prime;
int ada[80000];
bool isprime[1000002];

int main(){
	memset(isprime, true, sizeof isprime);
	isprime[0] = isprime[1] = false;
	for(ll i=2;i<1000000;++i){
		if(isprime[i]){
			prime.pb(i);
			for(ll j=i*i;j<1000000;j+=i)
				isprime[j] = false;
		}
	}
	scanf("%d", &t);
	while(t--){
		memset(ada, 0, sizeof ada);
		scanf("%d", &n);
		for(i=0;i<n;++i){
			scanf("%d", a+i);
			int sq = sqrt(a[i]);
			for(j=0;a[i]>1&&prime[j]<=sq;++j){
				if(a[i]%prime[j]==0){
					ada[j]++;
					do{
						a[i]/=prime[j];
					}while(a[i]%prime[j]==0);
				}
			}
			if(a[i]>1)
				ada[lower_bound(prime.begin(), prime.end(), a[i])-prime.begin()]++;
		}
		int ans = 0;
		for(i=0;i<prime.size();++i)
			ans += (ada[i]+2)/3;
		printf("%d\n", ans);
	}
	return 0;
}