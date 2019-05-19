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
int l, r;
int cnt[3];
int dp[200003][3];

int solve(int idx, int rem){
    int &ans = dp[idx][rem];
    if(ans == -1){
        ans = 0;
        for(int i=0;i<3;++i){
            ans += 1LL * cnt[i] * solve(idx-1, (rem + i)%3) % mod;
            ans %= mod;
        }
    }
    return ans;
}

int main(){
	scanf("%d %d %d", &n, &l, &r);
    cnt[0] = r/3 - (l-1)/3;
    cnt[1] = (r+2)/3 - (l+1)/3;
    cnt[2] = (r+1)/3 - (l)/3;
    cerr<<cnt[0]<<" "<<cnt[1]<<" "<<cnt[2]<<endl;
    memset(dp, -1, sizeof dp);
    memset(dp[0], 0, sizeof dp[0]);
    dp[0][0] = 1;
    printf("%d\n", solve(n, 0));
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