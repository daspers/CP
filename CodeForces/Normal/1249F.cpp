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
int a[202];
vector<int> adj[202];
int dp[202][202];

int dfs(int v, int p, int rem){
    int &ans = dp[v][rem];
    if(ans == -1){
        ans = 0;
        if(rem == 0){
            int tmp = a[v];
            for(int x : adj[v]){
                if(x == p) continue;
                tmp += dfs(x, v, k);
            }
            ans = max(ans, tmp);
        }
        if(rem > (k+1)/2){
            int tmp = 0;
            for(int x : adj[v]){
                if(x == p) continue;
                tmp += dfs(x, v, max(rem-1, 0));
            }
            ans = max(ans, tmp);
        }
        for(int i=max(1, rem);i<=(k+1)/2;++i){
            for(int x : adj[v]){
                if(x == p) continue;
                int tmp = 0;
                for(int y : adj[v]){
                    if(y == p) continue;
                    if(x == y) {
                        tmp += dfs(y, v, i-1);
                    }
                    else {
                        tmp += dfs(y, v, k-i);
                    }
                }
                ans = max(ans, tmp);
            }
        }
    }
    return ans;
}

int main(){
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;++i){
        scanf("%d", a+i);
    }
    for(int i=1;i<n;++i){
        int a, b;
        scanf("%d %d", &a, &b);
        --a, --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int ans = 0;
    memset(dp, -1, sizeof dp);
    ans = max(ans, dfs(0, 0, 0));
    printf("%d\n", ans);
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