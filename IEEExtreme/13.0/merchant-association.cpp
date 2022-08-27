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
int a[200002], b[200002];
bool ism[200002];
int dp[200002];
pii dw[200002];
pii up[200002];
vector<int> adj[200002], c[200002];
stack<int> st;

void dfsdp(int v, int p){
    up[v] = dw[v] = {b[v], b[v]};
    if(!ism[p] && up[p].se - min(up[p].fi, up[v].fi) > up[v].se - up[v].fi){
        up[v].fi = min(up[p].fi, up[v].fi);
        up[v].se = up[p].se;
    }
    for(int x : adj[v]){
        if(x == p) continue;
        dfsdp(x, v);
        if(ism[x]) continue;
        if(dw[x].se - min(dw[x].fi, dw[v].fi) > dw[v].se - dw[v].fi){
            dw[v].fi = min(dw[x].fi, dw[v].fi);
            dw[v].se = dw[x].se;
        }
    }
}

void dfs(int v, int p){
    if(ism[v]) st.push(v);
    c[st.top()].pb(i);
    for(int x : adj[v]){
        if(x == p) continue;
        dfs(x, v);
    }
    if(ism[v]) st.pop();
}

int main(){
    scanf("%d", &n);
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
    for(int i=0;i<m;++i){
        scanf("%d", b[i]);
        ism[b[i]] = true;
    }
    for(int i=0;i<n;++i){
        if(adj[i].size() == 1){
            dfs(i, i);
            break;
        }
    }
    ll sum = 0;
    for(int i=0;i<n;++i){
        sum += dp[i];
    }
    printf("%lld\n", sum);
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