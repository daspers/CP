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

int n,i,j,k,t;
int m;
vector<int> adj[500002];
bool vis[500002][2];
int par[500002];
int sz[500002];
bool viss[500002];
int cc;
bool sets[500002];

int find_set(int a){
    if(par[a] == a)
        return a;
    return par[a] = find_set(par[a]);
}

void merge(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a!=b){
        par[b] = a;
        sz[a] += sz[b];
        cc--;
    }
}

int main(){
    memset(vis, false, sizeof vis);
    memset(viss, false, sizeof viss);
    memset(sets, false, sizeof sets);
    scanf("%d %d", &n, &m);
    for(i=1;i<=n;++i){
        par[i] = i;
        sz[i] = 1;
    }
    cc = n;
    for(i=0;i<m;++i){
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
        merge(a, b);
    }
    int ans = 0;
    int ada = 0;
    for(i=1;i<=n;++i){  
        if(vis[i][1]) continue;
        // cout<<i<<endl;
        queue<pii> q;
        if(viss[find_set(i)] || sz[find_set(i)]==1){
            ada ++;
        }
        viss[i] = true;
        vis[i][1] = true;
        q.push({i,1});
        while(!q.empty()){
            pii tmp = q.front();
            q.pop();
            tmp.se ^= 1;
            for(int x : adj[tmp.fi]){
                if(vis[x][tmp.se]) continue;
                vis[x][tmp.se] = true;
                viss[x] = true;
                q.push({x, tmp.se});
            }
        }
    }
    ans = cc - 1;
    if(cc == 1 && ada)
        ans++;
    else if(ada == cc){
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}