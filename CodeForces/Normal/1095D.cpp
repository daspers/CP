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
int l[200002];
int r[200002];
set<int> adj[200003];
bool vis[200002];

void print(int v, int ot){
    if(vis[v]) return;
    vis[v] = true;
    printf("%d ", v);
    if(v == ot){
        set<int>::iterator a, b;
        a = adj[v].begin();
        b = ++adj[v].begin();
        if(adj[*a].count(*b)){
            print(*a, *b);
        }
        else{
            print(*b, *a);
        }
    }
    else{
        adj[v].erase(ot);
        print(ot, *adj[v].begin());
    }
}

int main(){
	scanf("%d", &n);
    for(i=1;i<=n;++i){
        scanf("%d %d", l+i, r+i);
        adj[i].insert(l[i]);
        adj[i].insert(r[i]);
    }
    memset(vis, 0, sizeof vis);
    print(1, 1);
    puts("");
	return 0;
}