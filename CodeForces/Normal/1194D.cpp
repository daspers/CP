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
int dp[10000][2];

int solve(int val, int turn){
    if(dp[val][turn] != -1) return dp[val][turn];
    int preturn = turn ^ 1;
    if(solve(val-1, preturn) == turn) return dp[val][turn] = turn;
    if(val >= 2 && solve(val-2, preturn) == turn) return dp[val][turn] = turn;
    if(val >= k && solve(val-k, preturn) == turn) return dp[val][turn] = turn;
    return dp[val][turn] = preturn;
}

void bf(){
    memset(dp, -1, sizeof dp);
    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[1][0] = dp[2][0] = 0;
    dp[1][1] = dp[2][1] = 1;
    cerr<<"start "<<k<<endl;
    for(int i=0;i<=200;++i){
        if(!solve(i, 1))
            cerr<<i<<" ";
    }
    cerr<<endl;
}

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        // bf();
        if(n == 0)
            puts("Bob");
        else if(n == k || n < 3)
            puts("Alice");
        // else if(k==3){
        //     puts((n % 4 == 0)? "Bob" : "Alice");
        // }
        else if(k % 3 == 0) {
            if( n < k){
                puts((n % 3 == 0)? "Bob" : "Alice");
            }
            else {
                int divi = (n) / (k + 1);
                int curr = n - divi * (k+1);
                puts((curr % 3 == 0 && curr != k)? "Bob" : "Alice");
            }
        }
        else {
            puts((n % 3 == 0)? "Bob" : "Alice");
        }
    }
	return 0;
}

/**
 * 1 -> alice
 * 2 -> alice
 * k -> alice
 */

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