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
pii a[5002];
vector<int> adj[5002];
bool is_cycle = false;
int vis[5002];

void dfs(int v) {
    vis[v] = 1;
    // cerr<<"masuk "<<v<<endl;
    for(int x : adj[v]){
        // cerr<<"lihat "<<x<<" "<<vis[x]<<endl;
        if(vis[x]){
            is_cycle |= vis[x] == 1;
            continue;
        }
        dfs(x);
    }
    // cerr<<"keluar "<<v<<endl;
    vis[v] = 2;
}

int main(){
	scanf("%d %d", &n, &m);
    for(int i=0;i<m;++i){
        scanf("%d %d", &a[i].fi, &a[i].se);
        adj[a[i].fi].pb(a[i].se);
    }
    for(int i=1;i<=n;++i){
        // memset(vis, 0, sizeof vis);
        if(vis[i]) continue;
        dfs(i);
    }
    if(is_cycle){
        puts("2");
        for(int i=0;i<m;++i){
            printf(a[i].fi < a[i].se ? "1 " : "2 ");
        }
        puts("");
    }
    else{
        puts("1");
        for(int i=0;i<m;++i){
            printf("1 ");
        }
        puts("");
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