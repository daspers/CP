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
int a[2003], b[2003];
int dp[2003][2003];
int ma[2003][2003];
int sum[2003];

int getsum(int l, int r){
    if(l==0) return sum[r];
    int ans = sum[r] - sum[l-1];
    return (mod + ans) % mod;
}

pii range(int *ma, int c, int ql, int qr){
    pii res = {-1, -1};
    int l = ql,  r = qr;
    while(l < r){
        int mid = (l+r+1)/2;
        if(ma[mid] < c){
            r = mid - 1;
        }
        else {
            l = mid;
        }
    }
    res.se = l;
    if(l > r || ma[r] != c){
        return res;
    }
    l = ql; r = res.se;
    while(l < r){
        int mid = (l+r)/2;
        if(ma[mid] > c){
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }
    if(r < l || r > res.se || ma[r] != c)
        return res;
    res.fi = r;
    return res;
}

int main(){
	scanf("%d %d", &n, &m);
    for(int i=0;i<n;++i){
        scanf("%d", a+i);
        ma[i][i] = a[i];
    }
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            ma[i][j] = max(ma[i][j-1], a[j]);
            ma[j][i] = ma[i][j];
        }
        // printArray(ma[i], n);
    }
    for(int i=0;i<m;++i)
        scanf("%d", b+i);
    memset(dp, 0, sizeof dp);
    // printArray(a, n);
    for(int i=0;i<m;++i){
        if (i==0){
            for(int j=i;j<n;++j){
                if(ma[0][j] != b[i]) continue;
                dp[i][j] = 1;
            }
        }
        else{
            for(int j=0;j<n;++j){
                if(j){
                    sum[j] = (sum[j-1] + dp[i-1][j]) % mod;
                }
                else
                    sum[j] = dp[i-1][j];
            }
            for(int j=i;j<n;++j){
                // cerr<<i<<" "<<j<<endl;
                pii tmp = range(ma[j], b[i], i, j);
                cerr<<"> "<<i<<" "<<j<<" "<<b[i]<<" ("<<tmp.fi<<" "<<tmp.se<<")"<<endl;
                for(int x=max(tmp.fi-2, 0);x<=j;++x){
                    cerr<<ma[j][x]<<" ";
                }
                cerr<<endl;
                if(tmp.fi == -1) continue;
                dp[i][j] = (dp[i][j] + getsum(tmp.fi, tmp.se)) % mod;
                // for(int k=0;k<j;++k){
                //     if(ma[k+1][j] != b[i]) continue;
                //     dp[i][j] += dp[i-1][k];
                // }
            }
        }
        printArray(dp[i], n);
    }
    printf("%d\n", dp[m-1][n-1]);
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