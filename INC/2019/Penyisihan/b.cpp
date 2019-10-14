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
pii a[102];
ll dp[101][10002];

int main(){
	scanf("%d %d", &n, &m);
    int sum = 0;
    for(int i=1;i<=n;++i){
        scanf("%d %d", &a[i].fi, &a[i].se);
        sum += a[i].se;
    }
    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;
    // memset(dp[0], 0, sizeof(int) * 10001);
    for(int i=1;i<=n;++i){
        memcpy(dp[i], dp[i-1], sizeof(int) * 10001);
        ll val = a[i].fi;
        ll sumval = val;
        for(int j=a[i].se/2;j>=0 && sumval <= 10000000000LL;j/=2){
            int loss = a[i].se - j;
            for(int k=0;k<=sum - loss;++k){
                if(dp[i-1][k] == -1) continue;
                dp[i][k+loss] = max(dp[i][k+loss], dp[i-1][k] + sumval);
            }
            if(j == 0) break;
            val *=2;
            sumval += val;
        }
        // for(int k=0;k<=sum;++k){
        //     cerr<<dp[i][k]<<" ";
        // }
        // cerr<<endl;
    }
    int ans = -1;
    for(int i=0;i<=sum;++i){
        if(dp[n][i] >= m){
            ans = i;
            break;
        }
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