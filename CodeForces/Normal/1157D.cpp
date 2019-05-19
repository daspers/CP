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
ll ans[100002];

int main(){
    ll n;
	scanf("%lld %d", &n, &k);
    if(1LL*k*(k+1)/2 > n){
        return puts("NO"), 0;
    }
    ll st = (n - 1LL*k*(k+1)/2) / k;
    int len = k;
    ll lim = 1e9;
    memset(ans, 0, sizeof ans);
    for(int i=0;i<k;++i, len--){
        ll must = 1LL * len * (len-1) / 2;
        ll rem = n - must;
        int add = min(rem / len, lim);
        ll dec = 1LL*add * len;
        if(i) ans[i] = ans[i-1];
        ans[i] += add;
        n -= dec;
        lim = ans[i];
    }
    if(n > 0){
        return puts("NO"), 0;
    }
    puts("YES");
    for(int i=0;i<k;++i){
        printf("%lld ", ans[i]);
    }
    puts("");
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