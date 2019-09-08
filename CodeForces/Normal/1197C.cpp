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
int a[300002];
int tree[1200005];

int main(){
	scanf("%d %d", &n, &k);
    for(int i=0;i<n;++i){
        scanf("%d", a+i);
    }
    // dp[i] = max(i, j-1) - min(i, j-1) + dp[j];
    /** kn^2
     * dp[i][0] = 0;
     * dp[i][1] = a[i] - a[1]
     * dp[i][k] = min(a[i] - a[j+1] + dp[j][k-1]) -> a[n] - a[x1] + a[x1-1] - a[x2] + a[x2-1] -a[1]
     */
    vector<int> v;
    for(int i=1;i<n;++i){
        v.pb(a[i-1] - a[i]);
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    for(int i=0;i<k-1;++i){
        ans += v[i];
        // cerr<<v[i]<<endl;
    }
    ans += a[n-1] - a[0];
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