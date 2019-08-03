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
vector<int> adj[200002];
int dep[200003];
bool vis[200002];
int ans[2];
int deg[200002];

void dfs(int v, int p){
    dep[v] = dep[p] + 1;
    for(int x : adj[v]){
        if(p == x) continue;
        dfs(x, v);
    }
}

int main(){
    scanf("%d", &n);
    for(int i=1;i<n;++i){
        int a,b;
        scanf("%d %d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    memset(dep, 0, sizeof dep);
    dfs(1, 1);
    int now = max_element(dep, dep+n+1) - dep;
    memset(dep, 0, sizeof dep);
    dfs(now, now);
    ans[0] = *max_element(dep, dep+n+1) - 1;
    for(int i=1;i<=n;++i)
        adj[i].clear();

    scanf("%d", &n);
    int rem = n;
    for(int i=1;i<n;++i){
        int a,b;
        scanf("%d %d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    queue<int> q;
    for(int i=1;i<=n;++i){
        deg[i] = adj[i].size();
        if(adj[i].size() == 1){
            q.push(i);
            deg[i] = 0;
        }
    }
    ans[1] = 0;
    while(rem > 2){
        int w = q.size();
        for(int i=0;i<w;++i){
            int tmp = q.front();
            rem--;
            q.pop();
            for(int x : adj[tmp]){
                deg[x] --;
                if(deg[x] == 1){
                    q.push(x);
                }
            }
        }
        ans[1]++;
    }

    if(rem > 1)
        ans[1]++;

    puts(ans[1] < ans[0] ? "GGEZ" : "FF");
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