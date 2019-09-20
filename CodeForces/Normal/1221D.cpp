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
int a[300005], b[300005];
ll dp[300004][5];
/** flag: relation of idx-1 to idx
 * 0: under / >+3
 * 1: equal
 * 2: +1
 * 3: +2
 * 4: +3
*/

int get(int idx){
    if(idx < 0 || idx >=n) return 0;
    return a[idx];
}

inline int get_flag(int a, int b){
    if(a == b) return 1;
    if(a == b+1) return 2;
    if(a == b+2) return 3;
    if(a == b+3) return 4;
    return 0;
}

ll solve(int idx, int flag){
    ll &ans = dp[idx][flag];
    if(ans == -1){
        if(idx >= n) ans = 0;
        else {
            if(flag == 0){
                ans = solve(idx+1, get_flag(a[idx], get(idx+1)));
                ans = min(ans, b[idx] + solve(idx+1, get_flag(a[idx]+1, get(idx+1))));
                ans = min(ans, 2*b[idx] + solve(idx+1, get_flag(a[idx]+2, get(idx+1))));
                ans = min(ans, 3LL*b[idx] + solve(idx+1, get_flag(a[idx]+3, get(idx+1))));
            }
            else if (flag == 1){
                ans = b[idx] + solve(idx+1, get_flag(a[idx]+1, get(idx+1)));
                ans = min(ans, 2*b[idx] + solve(idx+1, get_flag(a[idx]+2, get(idx+1))));
                ans = min(ans, 3LL*b[idx] + solve(idx+1, get_flag(a[idx]+3, get(idx+1))));
            }
            else if(flag == 2) { 
                ans = solve(idx+1, get_flag(a[idx], get(idx+1)));
                ans = min(ans, 2*b[idx] + solve(idx+1, get_flag(a[idx]+2, get(idx+1))));
                ans = min(ans, 3LL*b[idx] + solve(idx+1, get_flag(a[idx]+3, get(idx+1))));
            }
            else if(flag == 3) {
                ans = solve(idx+1, get_flag(a[idx], get(idx+1)));
                ans = min(ans, b[idx] + solve(idx+1, get_flag(a[idx]+1, get(idx+1))));
                ans = min(ans, 3LL*b[idx] + solve(idx+1, get_flag(a[idx]+3, get(idx+1))));
            }
            else {
                ans = solve(idx+1, get_flag(a[idx], get(idx+1)));
                ans = min(ans, b[idx] + solve(idx+1, get_flag(a[idx]+1, get(idx+1))));
                ans = min(ans, 2*b[idx] + solve(idx+1, get_flag(a[idx]+2, get(idx+1))));
            }
        }
    }
    return ans;
}

int main(){
	scanf("%d", &t);
    for(int cc=1;cc<=t;++cc){
	    scanf("%d", &n);
        for(int i=0;i<n;++i){
            scanf("%d %d", a+i, b+i);
        }
        memset(dp, -1, 5 * (n+2) * sizeof(ll));
        ll ans = solve(0, 0);
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