#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-9
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

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
int a[100002][4];
ll dp[100002][4];
int b[100002];

int main(){
	scanf("%d", &t);
    for(int cc=1;cc<=t;++cc){
        scanf("%d %d", &n, &m);
        for(int i=1;i<=n;++i){
            scanf("%d %d %d %d", a[i], a[i]+1, a[i]+2, a[i]+3);
        }
        for(int i=0;i<m;++i){
            int x;
            scanf("%d", &x);
            b[x] = cc;
        }
        // for(int i=1;i<=n;++i){
        //     ll ma = max(max(dp[i-1][0], dp[i-1][1]),max(dp[i-1][2], dp[i-1][3]));
        //     dp[i][0] = ma + a[i][0];
        //     dp[i][1] = ma + a[i][1];
        //     dp[i][2] = ma + a[i][2];
        //     dp[i][3] = ma + a[i][3];
        //     if(b[i-1] == cc){
        //         dp[i][0] = max(dp[i][0], dp[i-1][0] + 2 * a[i][0]);
        //         dp[i][1] = max(dp[i][1], dp[i-1][1] + 2 * a[i][1]);
        //         dp[i][2] = max(dp[i][2], dp[i-1][2] + 2 * a[i][2]);
        //         dp[i][3] = max(dp[i][3], dp[i-1][3] + 2 * a[i][3]);
        //     }
        // }
        printf("Case #%d: %lld\n", cc, *max_element(dp[n], dp[n]+4));
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