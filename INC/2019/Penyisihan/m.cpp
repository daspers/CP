#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-9
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void printArray(const int *arr, int n);
void printArray(const vector<int> &arr);

const ll mod = 1e9+7;
const double PI = acos(-1);

int n,i,j,k,t;
int m;

ll fac[200002];

void factorize(){
	fac[0] = 1;
	for(int i=1;i<200002;i++){
		fac[i] = (ll)i*fac[i-1];
		fac[i] %= mod;
	}
}

ll modPow(ll a, ll b){
	if(b == 0){return 1;}
	else{
		if(b%2 == 1){return a*modPow(a,b-1)%mod;}
		else{
			ll temp = modPow(a,b/2);
			return temp*temp%mod;
		}
	}
}

ll inv(ll a){
	return modPow(a,mod-2);
}

ll comb(ll a, ll b){
	ll ans = fac[a]*inv(fac[a-b]);
	// printf("ans: %lld %lld\n",ans, fac[a]);
	ans %= mod;
	ans *= inv(fac[b]);
	ans %= mod;
	return ans;
}

ll combi(ll a, ll b, ll c){
	ll ans = fac[a]*inv(fac[c]);
	// printf("ans: %lld %lld\n",ans, fac[a]);
	ans %= mod;
	ans *= inv(fac[b]);
	ans %= mod;
	return ans;
}

int main(){
	factorize();
	scanf("%d %d", &n, &m);
    if(m+1 < (n+1)/2) return puts("0"), 0;
    ll ans = comb(n+m, m);
    int mul = -1;
    for(int i=3;i<=n;++i){
        cerr<<i<<" "<<mul*comb(n-i+m, m)<<endl;
        ans = (ans + mul*comb(n-i+m, m) % mod) % mod;
        mul *= -1;
    }
    printf("%lld\n", ans);
	return 0;
}

/* Template Function */
void printArray(const int * a, int n){
	for(int i=0;i<n;++i){
		printf("%d ", a[i]);
	}
	puts("");
}

void printArray(const vector<int> &arr){
	for(int x : arr){
		printf("%d ", x);
	}
	puts("");
}