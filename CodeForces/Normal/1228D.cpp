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
int col[300002];
int cnt[4];
bool vis[300002];
vector<int> adj[300002];
set<int> sterile[4];
bool bisa = true;

void dfs(int v, int c){
    col[v] = c;
    vis[v] = true;
    cnt[c]++;
    for(int x : adj[v]){
        sterile[c].insert(x);
    }
    for(int x : adj[v]){
        if(!vis[x]){
            int tcol = 0;
            for(int i=1;i<=3;++i){
                if(i == c) continue;
                if(sterile[i].count(x)) continue;
                tcol = i;
                break;
            }
            if(tcol == 0){
                bisa = false;
            }
            dfs(x, tcol);
        }
    }
}

int main(){
	scanf("%d %d", &n, &m);
    for(int i=0;i<m;++i){
        int a,b;
        scanf("%d %d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i=1;i<=n;++i){
        if(adj[i].size()<2){
            bisa = false;
        }
    }
    if(bisa){
        dfs(1, 1);
        for(int i=1;i<=n;++i){
            if(col[i] == 0){
                bisa = false;
            }
        }
        if(cnt[1] + cnt[2] + cnt[3] != n){
            bisa = false;
        }
        for(int i=1;i<=3;++i){
            if(cnt[i] == 0 || sterile[i].size() != n - cnt[i])
                bisa = false;
        }
        for(int i=1;i<=n;++i){
            if(adj[i].size() != n - cnt[col[i]]){
                bisa = false;
            }
        }
    }
    if(bisa){
        for(int i=1;i<=n;++i){
            printf("%d ", col[i]);
        }
        puts("");
    }
    else{
        puts("-1");
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