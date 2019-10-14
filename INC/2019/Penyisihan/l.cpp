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
vector<pii> adj[100002], adj2[100002], vv, lucu[100002];
bool vis[100002];
int dep[100002], posv[100002], cep[100002];
int low[100002],dfn[100002],times,q[100002],head,scc_cnt,scc[100002];
int sz[100002], fam_head[100002];
int cnd[100002];
int l;
int timer;
vector<vector<int>> up;
vector<vector<int>> mi;

void dfs(int v, int p, int d){
    low[v] = ++timer;
    up[v][0] = p;
    dep[v] = dep[p]+1;
    mi[v][0] = d;
    for (int i = 1; i <= l; ++i){
        up[v][i] = up[up[v][i-1]][i-1];
        mi[v][i] = min(mi[up[v][i-1]][i-1], mi[v][i-1]);
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

int shortest_path(int u, int v){
    int anc = lca(u, v);
    return dep[u] + dep[v] - 2*dep[anc];
}

int query(int u, int v){
    if(u == v) return 100000;
    int res = 100000;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v)){
            u = up[u][i];
            res = min(res, mi[u][i]);
        }
    }
    return min(res, mi[u][0]);
}

void preprocess(int root) {
    timer = 0;
    l = ceil(log2(scc_cnt));
    up.assign(2*n, vector<int>(l + 1));
    mi.assign(2*n, vector<int>(l + 1, 100000));
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
            sz[scc_cnt]++;
            if(x==u)break;
        }
    }
}

void dfs_gila(int v, int cc=100000){
    posv[v] = vv.size();
    vv.pb({v, cc});
    for(const pii &x : adj[v]){
        if(vis[x.fi] || scc[x.fi] != scc[v]) continue;
        vis[x.fi] = true;
        dfs_gila(x.fi, x.se);
    }
}

void dfs_dicky(int v, int sc, int ed){
    cep[v] = ed;
    vis[v] = true;
    for(pii x : adj[v]){
        if(vis[x.fi] || scc[x.fi] == sc) continue;
        dfs_dicky(x.fi, sc, ed);
    }
}

int tree[400004];

void build(int l, int r, int pos){
    if(l == r){
        tree[pos] = vv[l].se;
        return;
    }
    int mid = (l+r)/2;
    build(l, mid, 2*pos+1);
    build(mid+1, r, 2*pos+2);
    tree[pos] = min(tree[2*pos+1], tree[2*pos+2]);
}

int idx, val;
void update(int l, int r, int pos){
    if(l > idx || r < idx) return;
    if(l == r){
        tree[pos] = val;
        return;
    }
    int mid = (l+r)/2;
    update(l, mid, 2*pos+1);
    update(mid+1, r, 2*pos+2);
    tree[pos] = min(tree[2*pos+1], tree[2*pos+2]);
}

int ql, qr;
int query(int l, int r, int pos){
    if(l>qr) return 100000;
    if(r <= qr) return tree[pos];
    int mid = (l+r)/2;
    return min(
        query(l, mid, 2*pos+1),
        query(mid+1, r, 2*pos+2)
    );
}

int main(){
	scanf("%d %d", &n, &t);
    for(int i=0;i<n;++i){
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        --a, --b;
        // cerr<<a<<" "<<b<<" "<<c<<endl;
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }
    tarjan(0, 0);
    // printArray(scc, n);
    int spnode = scc[0];
    set<int> endp;
    for(int i=0;i<n;++i){
        if(sz[scc[i]] > 1){
            spnode = scc[i];
            if(adj[i].size()>2){
                endp.insert(i);
            }
        }
    }
    for(int x : endp){
        dfs_dicky(x, scc[x], x);
    }
    // printArray(cep, n);
    memset(vis, false, sizeof vis);
    // debug(*endp.begin());
    dfs_gila(*endp.begin());
    int lol = vv.size();
    for(int i=1;i<lol;++i){
        vv.pb(vv[i]);
    }
    build(1, vv.size(), 0);
    for(int i=0;i<n;i++){
        for(pii v:adj[i]){
            if(scc[i]!=scc[v.fi]){
                adj2[scc[i]].push_back({scc[v.fi], v.se});
            }
        }
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
    preprocess(scc[0]);
    while(t--){
        int a, b;
        scanf("%d %d", &a, &b);
        --a, --b;
        int sa = scc[a];
        int sb = scc[b];
        int ans = 200000;
        if(sa == spnode && sb == spnode){
            // cerr<<"DICKY"<<endl;
            int c = posv[a];
            int d = posv[b];
            if(c > d){
                swap(c, d);
            }
            ql = c+1;
            qr = d;
            int ss = query(1, vv.size(), 0);
            ql = d+1;
            qr = c + lol;
            ss += query(1, vv.size(), 0);
            ans = min(ans, ss);
        }
        else if(sa == spnode || sb == spnode){
            // cerr<<"Yonas"<<endl;
            if(sb == spnode){
                swap(sa, sb);
                swap(a, b);
            }
            int anc = lca(sa, sb);
            if(sa != anc){
                ans = min(ans, query(sa, anc));
                // debug(query(sa, anc));
            }
            if(sb != anc){
                ans = min(ans, query(sb, anc));
                // debug(query(sb, anc));
            }
            // cerr<<a<<" "<<b<<endl;
            if(cep[b] != a){
                int c = posv[a];
                int d = posv[cep[b]];
                if(c > d){
                    swap(c, d);
                }
                ql = c+1;
                qr = d;
                int ss = query(1, vv.size(), 0);
                ql = d+1;
                qr = c + lol;
                ss += query(1, vv.size(), 0);
                ans = min(ans, ss);
            }
        }
        else {
            // cerr<<"Juara"<<endl;
            int anc = lca(sa, sb);
            ans = min(query(sa, anc), query(sb, anc));
            if(shortest_path(a, b) == shortest_path(a, spnode) + shortest_path(b, spnode)){
                int c = posv[cep[a]];
                int d = posv[cep[b]];
                if(c > d){
                    swap(c, d);
                }
                ql = c+1;
                qr = d;
                int ss = query(1, vv.size(), 0);
                ql = d+1;
                qr = c + lol;
                ss += query(1, vv.size(), 0);
                ans = min(ans, ss);
            }
        }
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