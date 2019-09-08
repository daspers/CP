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
int a[1003];
unordered_map<int, int> dp[2][1000];

int solve(int turn, int ls, int sum){
    if(!dp[turn][ls].count(sum)){
        int ans = 0;
        if(sum > ls * n){
            ans = max(ans, 1^solve(turn^1, ls, sum-1));
        }
        if(ls > 0){
            ans = max(ans, 1^solve(turn^1, ls-1, sum-1));
            ans = max(ans, 1^solve(turn^1, ls-1, sum-n));
        }
        return dp[turn][ls][sum] = ans;
    }
    return dp[turn][ls][sum];
}

int main(){
	scanf("%d", &n);
    int sum = 0 ;
    for(int i=0;i<n;++i){
        scanf("%d", a+i);
        sum += a[i];
    }
    int mi = *min_element(a, a+n);
    dp[1][0][0] = dp[0][0][0] = 0;
    puts(solve(1, mi, sum) ? "lowie" : "imitater");
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