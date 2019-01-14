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
vector<int> adj[100002];
int p[100002];
int a[100002], s[100002];
int dep[100002];
ll ans = 0;

int check(int v){
    int ma = 1e9;
    for(int x: adj[v]){
        ma = min(ma, check(x));
    }
    // cout<<"woah : "<<v<<" "<<s[v]<<" "<<ma<<endl;
    if(s[v] != -1 && ma < s[v]){
        puts("-1");
        exit(0);
    }
    if(s[v] != -1)
        ma = min(ma, s[v]);
    return ma;
}

void dfs(int v){
    if(adj[v].size()==0){
        if(s[v] == -1)
            s[v] = s[p[v]];
        ans += s[v];
        // cout<<"add "<<s[v]<<endl;
        return;
    }
    int mi = 1e9;
    for(int x : adj[v]){
        dfs(x);
        mi = min(mi, s[x]);
    }
    if(s[v] == -1)
        s[v] = mi;
    // cout<<"graph : "<<v<<" "<<s[v]<<endl;
    if(adj[v].size() > 1){
        ans -= 1LL*(adj[v].size()-1) * s[v];
        // cout<<"dec "<<adj[v].size()-1<<" "<<s[v]<<endl;
    }
}

int main(){
    scanf("%d", &n);
    for(i=2;i<=n;++i){
        scanf("%d", p+i);
        adj[p[i]].pb(i);
    }
    for(i=1;i<=n;++i)
        scanf("%d", s+i);
    check(1);
    dfs(1);
    printf("%lld\n", ans);
    return 0;
}