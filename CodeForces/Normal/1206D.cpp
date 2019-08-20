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
ll a[100002];
vector<int> adj[64], lol[100003];
int vis[100002];
int dep[100002];
int globel = 0;
int cic = -1;

void setCic(int val){
    // cerr<<"kimak ada yang set"<<endl;
    if(cic == -1)
        cic = val;
    else
        cic = min(cic, val);
}

void dfs(int v, int p){
    // cerr<<"masuk "<<v<<" "<<p<<endl;
    // cerr<<"info: "<<endl;
    // cerr<<"  "; printArray(vis, n);
    // cerr<<"  "; printArray(dep, n);
    // cerr<<"  ";
    // for(int ii : lol[v]){
    //     for(int x : adj[ii]){
    //         cerr<<x<<" ";
    //     }
    // }
    // cerr<<endl;
    for(int ii : lol[v]){
        for(int x : adj[ii]){
            if(vis[x] == globel+n || x == p || x == v) continue;
            if(vis[x] == globel && dep[v] > dep[x]){
                int dist = abs(dep[v] - dep[x]) + 1;
                if(dist > 2){
                    setCic(dist);
                }
            }
            else if (dep[v] < 64){
                dep[x] = dep[v] + 1;
                vis[x] = globel;
                dfs(x, v);
            }
        }
    }
    dep[v] = globel+n;
    // cerr<<"keluar "<<v<<" "<<p<<" cic:"<<cic<<endl;
}

int main(){
	scanf("%d", &n);
    for(int i=0;i<n;++i){
        scanf("%lld", a+i);
        ll tmp = 1;
        for(int j=0;j<64;++j){
            if(a[i] & tmp) {
                adj[j].pb(i);
                lol[i].pb(j);
            }
            tmp *= 2;
        }
    }
    int mi = -1;
    for(int i=0;i<64;++i){
        if(adj[i].size() > 2){
            return puts("3"), 0;
        }
    }
    memset(dep, 0, sizeof dep);
    memset(vis, 0, sizeof vis);
    for(int i=0;i<n;++i){
        dep[i] = 0;
        globel = i+1;
        vis[i] = globel;
        setCic(-1);
        dfs(i, i);
        if(cic != -1){
            if(mi == -1)
                mi = cic;
            else
                mi = min(mi, cic);
        }
    }
    printf("%d\n", mi);
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