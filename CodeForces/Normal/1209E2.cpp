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
int ma[2002];
int a[14][2002];
int dp[2001][1<<12];
int adp[2001][1<<12];
int p[2001];

int get(int idx, int mask){
    int &ans = adp[idx][mask];
    if(ans == -1){
        ans = 0;
        for(int i=0;i<n;++i){
            int now = 1;
            int sum = 0;
            for(int j=0;j<n;++j){
                if(mask & now) {
                    sum += a[(i+j) % n][idx];
                }
                now <<=1;
            }
            ans = max(ans, sum);
        }
    }
    return ans;
}

int solve(int idx, int mask){
    int &ans = dp[idx][mask];
    if(ans == -1){
        if(idx >= min(n, m)) ans = 0;
        else{
            int id = p[idx];
            ans = solve(idx+1, mask);
            for(int i = mask;i > 0;i = (i-1) & mask){
                ans = max(ans, get(id, i) + solve(idx+1, mask ^ i));
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
        for(int i=0;i<m;++i){
            ma[i] = 0;
            for(int j=0;j<n;++j){
                ma[i] = max(ma[i], a[j][i]);
            }
            p[i] = i;
        }
        sort(p, p+m, [](int x, int y){
            return ma[x] > ma[y];
        });
        int ans = 0;
        memset(dp, -1, sizeof dp);
        memset(adp, -1, sizeof adp);
        ans = solve(0, (1<<n)-1);
        printf("%d\n", ans);
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