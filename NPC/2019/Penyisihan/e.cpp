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
vector<pii> adj[200002], adj2[200002];
int low[200002],dfn[200002],times,q[200002],head,scc_cnt,scc[200002];

int l;
int timer;
vector<vector<int>> up;
vector<vector<ll>> sum;

void dfs(int v, int p, int d){
    low[v] = ++timer;
    up[v][0] = p;
    sum[v][0] = d;
    for (int i = 1; i <= l; ++i){
        up[v][i] = up[up[v][i-1]][i-1];
        sum[v][i] = sum[up[v][i-1]][i-1] + sum[v][i-1];
    }

    for (const pii & u : adj2[v]) {
        if (u.fi != p)
            dfs(u.fi, v, u.se);
    }

    dfn[v] = ++timer;
}

bool is_ancestor(int u, int v){
    return low[u] <= low[v] && dfn[u] >= dfn[v];
}

int lca(int u, int v){
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

ll query(int u, int v){
    if(u == v) return 0;
    ll res = 0;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v)){
            u = up[u][i];
            res += sum[u][i];
        }
    }
    return res + sum[u][0];
}

void preprocess(int root) {
    timer = 0;
    l = ceil(log2(scc_cnt));
    up.assign(2*n, vector<int>(l + 1));
    sum.assign(2*n, vector<ll>(l + 1, 0));
    // cerr<<"wow"<<endl;
    dfs(root, root, 0);
}

void tarjan(int u,int f){
    dfn[u]=low[u]=++times;
    q[++head]=u;
    for(pii x:adj[u]){
        int i = x.fi;
        if(i==f)continue;
        if(!dfn[i]){
            tarjan(i,u);
            low[u]=min(low[u],low[i]);
        }
        else low[u]=min(low[u],dfn[i]);
    }
    if(low[u]==dfn[u]){
        scc_cnt++;
        while(true){
            int x=q[head--];
            scc[x]=scc_cnt;
            // sz[scc_cnt]++;
            if(x==u)break;
        }
    }
}

int main(){
	scanf("%d %d", &n, &m);
    for(int i=0;i<m;++i){
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        --a, --b;
        // cerr<<a<<" "<<b<<" "<<c<<endl;
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }
    tarjan(0, 0);
    for(int i=0;i<n;i++){
        for(pii v:adj[i]){
            if(scc[i]!=scc[v.fi]){
                adj2[scc[i]].push_back({scc[v.fi], v.se});
            }
        }
        sort(adj2[scc[i]].begin(), adj2[scc[i]].end());
        adj2[scc[i]].erase(unique(adj2[scc[i]].begin(), adj2[scc[i]].end(), [](const pii &a, const pii& b){
            return a.fi == b.fi;
        }), adj2[scc[i]].end());
    }
    // set<int> s;
    // cerr<<"wtf::"<<endl;
    // for(int i=0;i<n;++i){
    //     int v = scc[i];
    //     if(s.count(v)) continue;
    //     for(pii x : adj2[v]){
    //         cerr<<v<<" "<<x.fi<<" "<<x.se<<endl;
    //     }
    //     s.insert(v);
    // }
    // cerr<<"shit1"<<endl;
    preprocess(scc[0]);
    // cerr<<"shit2"<<endl;
    // cerr<<"shit2"<<endl;
    scanf("%d", &t);
    while(t--){
        int a, b;
        scanf("%d %d", &a, &b);
        --a, --b;
        a = scc[a];
        b = scc[b];
        if(a == b) puts("0");
        else {
            int anc = lca(a, b);
            printf("%lld\n", query(a, anc) + query(b, anc));
        }
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