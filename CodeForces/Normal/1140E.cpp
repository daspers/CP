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

const ll mod = 998244353;
const double PI = acos(-1);

int n,i,j,k,t;
int a[200002];
vector<int> b, c;
ll dps[200002][2];
ll dpd[200002][2];

ll modpow(ll a, int b){
    ll res = 1;
    for(;b;b>>=1){
        if(b & 1){
            res = res * a % mod;
        }
        a = a * a % mod;
    }
    return res;
}

int main(){
    scanf("%d %d", &n, &k);
    int hehe = false;
    for(int i=0;i<n;++i){
        scanf("%d", a+i);
        if(a[i] != -1 && i & 1){
            c.pb(i);
        }
        else if (a[i] != -1){
            b.pb(i);
        }
    }
    dps[1][0] = 0;
    dps[1][1] = k-1;
    dpd[1][0] = 1;
    dpd[1][1] = k-2;
    for(int i=2;i<=n;++i){
        dps[i][0] = dps[i-1][1];
        dps[i][1] = (dps[i-1][0] * (k-1) % mod + dps[i-1][1] * (k - 2) % mod) % mod;
        dpd[i][0] = dpd[i-1][1];
        dpd[i][1] = (dpd[i-1][0] * (k-1) % mod + dpd[i-1][1] * (k - 2) % mod) % mod;
    }
    ll ans = 1;
    for(int i=2;i<n;++i){
        if(a[i] != -1 && a[i] == a[i-2])
            return puts("0"), 0;
    }
    if(b.size() == 0){
        ans = ans * k % mod;
        ans = ans * modpow(k-1, (n + 1)/2 - 1) % mod;
    }
    else{
        ans = ans * modpow(k-1, b.front() / 2) % mod;
        ans = ans * modpow(k-1, (n - 1 - b.back()) / 2) % mod;
        for(int i=1;i<b.size();++i){
            if(a[b[i]] == a[b[i-1]])
                ans = ans * dps[(b[i] - b[i-1]) / 2][0] % mod;
            else
                ans = ans * dpd[(b[i] - b[i-1]) / 2][0] % mod;
        }
    }
    if(c.size() == 0){
        ans = ans * k % mod;
        ans = ans * modpow(k-1, n/2 - 1) % mod;
    }
    else{
        ans = ans * modpow(k-1, c.front() / 2) % mod;
        ans = ans * modpow(k-1, (n - 1 - c.back()) / 2) % mod;
        for(int i=1;i<c.size();++i){
            if(a[c[i]] == a[c[i-1]])
                ans = ans * dps[(c[i] - c[i-1]) / 2][0] % mod;
            else
                ans = ans * dpd[(c[i] - c[i-1]) / 2][0] % mod;
        }
    }
    printf("%lld\n", ans);
	return 0;
}

/* Template Function */
void printArray(int * a, int n){
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