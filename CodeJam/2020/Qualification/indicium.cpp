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
int a[51][51];
int dp[1<<18][18*18+1];
// int dp[5+1][1<<5][5*5+2];

int solve(int st, int rem){
    int &ans = dp[st][rem];
    if(ans == -1){
        int idx = n - __builtin_popcount(st);
        if(st == 0){
            ans = rem == 0;
        }
        else if(rem == 0){
            ans = 0;
        }
        else {
            ans = 0;
            for(int i=0;i<n;++i){
                int curr = 1 << i;
                if((curr & st) && a[idx][i] <= rem){
                    if(solve(st - curr, rem - a[idx][i])){
                        ans = 1;
                        break;
                    }
                }
            }
        }
        // debug4(idx, st, rem, ans);
    }
    return ans;
}

int main(){
    scanf("%d", &t);
    for(int cc=1;cc<=t;++cc){
        printf("Case #%d: ", cc);
        scanf("%d %d", &n, &k);
        if((k % n) || n > 18){
            puts("IMPOSSIBLE");
            continue;
        }
        puts("POSSIBLE");
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                a[i][j] = (i+j) % n + 1;
            }
        }
        memset(dp, -1, sizeof dp);
        // for(int i=n;i<=n*n;++i){
        //     printf("%d: ", i);
        //     for(int j=0;j<n;++j){
        //         if(!solve(1, (1<<n)-1-(1 << j), i - a[0][j])){
        //             printf("%d ", a[0][j]);
        //         }
        //     }
        //     puts("");
        // }
        int state = (1 << n) - 1;
        int rem = k;
        vector<int> ans;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                int curr = 1<<j;
                if(!(curr & state)) continue;
                if(solve(state - curr, rem - a[i][j])){
                    ans.pb(j);
                    state -= curr;
                    rem -= a[i][j];
                    break;
                }
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                printf("%d ", a[ans[i]][j]);
            }
            puts("");
        }
        // for(int i=n;i<=n*n;++i){
        //     if(solve((1<<n)-1, i)){
        //         printf("%d ", i);
        //     }
        // }
        // puts("");
    }
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