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
vector<int> adj[800005];
int f[800005];
vector<int> fn[800005];
bool visited[800005];
int ans;

vector<int> tin, low;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) {
                // debug2(v, to);
                ans+= f[to] != f[v];
            }
        }
    }
}

void find_bridges() {
    timer = 0;
    memset(visited, false, n + 2);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

int main(){
    scanf("%d", &t);
    for(int cc=1;cc<=t;++cc) {
        printf("Case #%d: ", cc);
        scanf("%d", &n);
        for(int i=1;i<n;++i) {
            int x, y;
            scanf("%d %d", &x, &y);
            --x; --y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for(int i=0;i<n;++i) {
            scanf("%d", f+i);
            --f[i];
            fn[f[i]].push_back(i);
        }
        for(int i=0;i<n;++i) {
            for(int j=1;j<fn[i].size();++j) {
                // debug2(fn[i][0], fn[i][j]);
                adj[fn[i][0]].push_back(fn[i][j]);
                adj[fn[i][j]].push_back(fn[i][0]);
            }
        }
        ans = 0;
        find_bridges();
        printf("%d\n", ans);
        for(int i=0;i<=n;++i) {
            adj[i].clear();
            fn[i].clear();
        }
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