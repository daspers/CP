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
int a[100];
vector<int> adj[100];
bool vis[100];
int dp[52][52];

int sumdfs(int v, int k) {
    int &ans = dp[v][k];
    if (ans == -1) {
        ans = 0;
        
        int ma = 0;
        for(int u : adj[v]) {
            if (!vis[u]) {
                ma = max(ma, sumdfs(u));
            }
        }
    }
    return ans;
}

int main(){
    scanf("%d", &t);
    for(int cc=1;cc<=t;++cc) {
        printf("Case #%d: ", cc);
        scanf("%d %d", &n, &k);
        for(int i=0;i<n;++i) {
            adj[i].clear();
            scanf("%d", a+i);
        }
        for(int i=1;i<n;++i) {
            int x,y;
            scanf("%d %d", &x, &y);
            adj[x-1].push_back(y-1);
            adj[y-1].push_back(x-1);
        }
        int ans = a[0];
        if (k > 0) {
            memset(dp, -1, sizeof dp);
            ans = sumdfs(0, k+1);
        }
        printf("%d\n", ans);
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