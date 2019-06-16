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
int a[200002];
vector<int> adj[200002];
map<int, int> mep[200002];
int ans;

void assignmax(map<int,int> &m, int key, int val){
    map<int,int>::iterator it = m.find(key);
    if(it == m.end()){
        m[key] = val;
    }
    else{
        it->se = max(it->se, val);
    }
}

void dfs(int v, int p, int d){
    // cerr<<v<<" "<<p<<" "<<d<<endl;
    for(int x : adj[v]){
        if(x == p) continue;
        // cerr<<"go "<<x<<endl;
        dfs(x, v, d+1);
        // cerr<<"out "<<x<<endl;
        for(const pii &w : mep[x]){
            int tmp = __gcd(w.fi, a[v]);
            if(tmp == 1) continue;
            ans = max(ans, w.se - d + 1);
            for(const pii &z : mep[v]){
                if(__gcd(tmp, z.fi) == 1) continue;
                ans = max(ans, z.se + w.se- 2*d + 1);
            }
        }
        for(const pii &w : mep[x]){
            int tmp = __gcd(w.fi, a[v]);
            if(tmp == 1) continue;
            assignmax(mep[v], tmp, w.se);
        }
        // cerr<<mep[v].size()<<endl;
    }
    if(a[v] > 1){
        ans = max(ans, 1);
        assignmax(mep[v], a[v], d);
    }
}

int main(){
	scanf("%d", &n);
    for(int i=0;i<n;++i)
        scanf("%d", a+i);
    for(int i=1;i<n;++i){
        int x, y;
        scanf("%d %d", &x, &y);
        --x, --y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(0, 0, 1);
    printf("%d\n", ans);
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