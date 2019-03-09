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

const ll mod = 1e9+7;
const double PI = acos(-1);

void printArray(int *arr, int n){
    for(int i=0;i<n;++i)
        printf("%d ", arr[i]);
    puts("");
}

int n,i,j,k,t;
int m;
vector<int> adj[100002], wew;

void dfs(int v, int p){
    for(int x : adj[v]){
        if(x == p) continue;
        dfs(x, v);
    }
    if(adj[v].size() == 1){
        wew.pb(v);
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i=1;i<n;++i){
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(m, m);
    int sz = wew.size();
    int s2 = (sz + 1)/2;
    vector<pii> ans;
    for(int i=0;i<s2;++i){
        ans.pb({wew[i], wew[sz + i - s2]});
    }
    // debug(wew.size());
    printf("%d\n", (int)ans.size());
    for(pii x : ans){
        printf("%d %d\n", x.fi, x.se);
    }
    return 0;
}