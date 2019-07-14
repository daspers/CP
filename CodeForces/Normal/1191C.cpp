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

ll n,i,j,k,t;
ll m;
ll a[1000002];
ll off = 0;

ll page(ll val) {
    return (val - off + k - 1) / k;
}

int main(){
	scanf("%lld %lld %lld", &n, &m ,&k);
    for(int i=0;i<m;++i){
        scanf("%lld\n", a+i);
    }
    ll ans = 0;
    for(int i=0;i<m;++i){
        if(i>0 && page(a[i]) != page(a[i-1])) {
            cerr<<a[i]<<endl;
            ans++;
            off=i;
        }
    }
    ans++;
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