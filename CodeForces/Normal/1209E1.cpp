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
int a[14][2002];
ll dp[102][1<<5];

ll solve(int idx, int mask){
    ll &ans = dp[idx][mask];
    if(ans == -1){
        if(idx >= m) ans = 0;
        else{
            ans = solve(idx+1, mask);
            for(int i = mask;i > 0;i = (i-1) & mask){
                ll ma = 0;
                for(int j=0;j<n;++j){
                    int now = 1;
                    ll sum = 0;
                    for(int k=0;k<n;++k){
                        if(i & now) {
                            sum += a[(j+k) % n][idx];
                        }
                        now <<=1;
                    }
                    ma = max(ma, sum);
                }
                ans = max(ans, ma + solve(idx+1, mask ^ i));
            }
        }
    }
    return ans;
}

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                scanf("%d", a[i]+j);
            }
        }
        ll ans = 0;
        memset(dp, -1, sizeof dp);
        ans = solve(0, (1<<n)-1);
        printf("%lld\n", ans);
    }
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