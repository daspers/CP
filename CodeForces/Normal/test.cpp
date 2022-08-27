#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-9
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define debug2(a, b) cerr<<#a<<"="<<(a)<<" ";debug(b)
#define debug3(a, b, c) cerr<<#a<<"="<<(a)<<" ";debug2(b, c)
#define debug4(a, b, c, d) cerr<<#a<<"="<<(a)<<" ";debug3(b, c, d)
#define debug5(a, b, c, d, e) cerr<<#a<<"="<<(a)<<" ";debug4(b, c, d, e)
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<class T>
void printArray(const T * a, int n, ostream& out = cerr);
template<class T>
void printArray(const vector<T> &arr, ostream& out = cerr);

const ll mod = 1e9+7;
const double PI = acos(-1);

int n,i,j,k,t;
int m;
int a[5002];
int b[5002];
int c[5002];
int dp[5002][5002];

int solve(int idx, int curr){
    int &ans = dp[idx][curr];
    if(ans == -1){
        if(curr == m){
            ans = c[idx] == 0;
        }
        else if(idx >= n){
            ans = curr == m;
        }
        else {
            if(a[idx] == 1){
                ans = 0;
                if(idx + b[curr] <= n && a[idx + b[curr]] == 0){
                    ans = solve(idx + b[curr] + 1, curr + 1);
                }
            }
            else {
                ans = solve(idx+1, curr);
                if(idx + b[curr] <= n && a[idx + b[curr]] == 0){
                    ans = (ans + solve(idx + b[curr] + 1, curr + 1)) % mod;
                }
            }
        }
    }
    return ans;
}

int main(){
    memset(dp, -1, sizeof dp);
    scanf("%d", &n);
    for(int i=0;i<n;++i){
        scanf("%d", a+i);
    }
    c[n-1] = a[n-1];
    for(int i=n-2;i>=0;--i){
        c[i] = a[i] + c[i+1];
    }
    scanf("%d", &m);
    for(int i=0;i<m;++i){
        scanf("%d", b+i);
    }
    // for(int j=0;j<=m;++j){
    //     for(int i=0;i<=n+1;++i){
    //         cerr<<solve(i, j)<<"\t";
    //     }
    //     cerr<<endl;
    // }
    printf("%d\n", solve(0, 0));
    return 0;
}

/* Template Function */
template<class T>
void printArray(const T * a, int n, ostream& out){
    for(int i=0;i<n;++i){
        out<<a[i]<<" ";
    }
    out<<endl;
}

template<class T>
void printArray(const vector<T> &arr, ostream& out){
    for(const T& x : arr){
        out<<x<<" ";
    }
    out<<endl;
}