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
vector<int> adj[100003];
bool vis[100003];
int cnt ;

void dfs(int v, int p){
    vis[v] = true;
    // cerr<<"masuk "<<v<<" "<<p<<endl;
    cnt++;
    for(int x : adj[v]){
        if(vis[x] || x == p) continue;
        dfs(x, v);
    }
}

int main(){
	scanf("%d %d", &n, &m);
    for(int i=0;i<m;++i){
        int a, b;
        scanf("%d %d", &a, &b);
        --a, --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int ans = 0;
    memset(vis, 0, sizeof vis);
    for(int i=0;i<n;++i){
        if(vis[i]) continue;
        cnt = 0;
        dfs(i, i);
        ans += cnt-1;
    }
    printf("%d\n", m - ans);
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