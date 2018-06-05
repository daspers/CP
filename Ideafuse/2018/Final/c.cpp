#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define INF 200000001
#define EPS 1e-9

typedef long long ll;
typedef complex<double> cd;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
int p2[32];

int pow2(int x){
	int res = 1;
	for(int i=0;x;++i){
		if(x&1)
			res = 1LL*res*p2[i] % mod;
		x >>= 1;
	}
	return res;
}

int main(){
	p2[0] = 2;
	for(i=1;i<32;++i)
		p2[i] = (1LL*p2[i-1]*p2[i-1]) % mod;
	scanf("%d", &t);
	for(int cc=1;cc<=t;++cc){
		printf("Case #%d: ", cc);
		scanf("%d %d", &n, &k);
		priority_queue<int> pq;
		vector<int> a;
		int maks = 0;
		for(i=0;i<n;++i){
			int x;
			scanf("%d", &x);
			pq.push(-x);
			maks = max(maks, x);
		}
		if(pq.top()==0){
			while(!pq.empty()){
				a.pb(-pq.top());
				pq.pop();
			}
		}
		else{
			while(k&&!pq.empty()){
				int tmp = -pq.top();
				pq.pop();
				if(2*tmp < maks){
					tmp *= 2;
					pq.push(-tmp);
					k--;
				}
				else
					a.pb(tmp);
			}
			while(!pq.empty()){
				a.pb(-pq.top());
				pq.pop();
			}
			if(k>0){
				sort(a.begin(), a.end());
				int sisa = k % n;
				int bagi = k / n;
				for(int i=0;i<n;++i){
					a[i] = (1LL*a[i]*pow2((sisa>0)+bagi)) % mod;
					sisa--;
				}
			}
		}
		ll ans = 0;
		for(int x : a){
			ans += x;
			ans %= mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
