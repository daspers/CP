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

const ll mod = 998244353;
const double PI = acos(-1);

int n,i,j,k,t;
int m;
bool nd[100002];
int par[100002], dep[100002];
int cnt[100002];
pair<int, pii> edge[100002];
vector<int> adj[100002];

int find_set(int v){
    if(par[v] == v)
        return v;
    return par[v] = find_set(par[v]);
}

bool union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        par[b] = a;
        return true;
    }
    return false;
}

void dfs(int v, int p){
    cnt[v] = nd[v];
    dep[v] = dep[p] + 1;
    for(int x : adj[v]){
        if(x == p) continue;
        dfs(x, v);
        cnt[v] += cnt[x];
    }
}

int main(){
    memset(nd, 0, sizeof nd);
    scanf("%d %d %d", &n, &m, &k);
    for(i=0;i<k;++i){
        int v;
        scanf("%d", &v);
        nd[v] = true;
    }
    for(i=1;i<=n;++i)
        par[i] = i;
    priority_queue<pii> pq;
    for(i=0;i<m;++i){
        scanf("%d %d %d", &edge[i].se.fi, &edge[i].se.se, &edge[i].fi);
        pq.push({-edge[i].fi, i});
    }
    vector<int> v;
    while(!pq.empty()){
        pii tmp = pq.top();
        pq.pop();
        if(union_set(edge[tmp.se].se.fi, edge[tmp.se].se.se)){
            adj[edge[tmp.se].se.fi].pb(edge[tmp.se].se.se);
            adj[edge[tmp.se].se.se].pb(edge[tmp.se].se.fi);
            v.pb(tmp.se);
        }
    }
    sort(v.begin(), v.end(), [](int a, int b) -> bool {
        return edge[a].fi > edge[b].fi;
    });
    dep[1] = -1;
    dfs(1,1);
    int ans = 0;
    for(int x : v){
        int a = edge[x].se.fi;
        int b = edge[x].se.se;
        if(dep[a] > dep[b]) swap(a, b);
        if(cnt[b] && cnt[b] < k){
            ans = edge[x].fi;
            break;
        }
    }
    for(i=0;i<k;++i)
        printf("%d ", ans);
    puts("");
	return 0;
}