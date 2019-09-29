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

int powmod(int a, ll b){
    int res = 1;
    for(;b;b>>=1){
        if(b&1){
            res = 1LL*a*res % mod;
        }
        a = 1LL*a*a%mod;
    }
    return res;
}

int main(){
    ll x;
	scanf("%d %lld", &n, &x);
    vector<int> v;
    int sq = sqrt(n);
    for(int i=2;i<=sq && i<=n;++i){
        if(n % i == 0){
            v.pb(i);
            do{
                n/=i;
            }while(n % i == 0);
        }
    }
    if(n > 1){
        v.pb(n);
    }
    int ans = 1;
    for(int y : v){
        ll tmp = x;
        ll cnt = 0;
        while(tmp){
            tmp /= y;
            cnt += tmp;
        }
        // cerr<<y<<" "<<cnt<<endl;
        ans = 1LL*ans*powmod(y, cnt) % mod;
    }
    printf("%d\n", ans);
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