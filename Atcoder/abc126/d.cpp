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
vector<pii> adj[100003];
int col[100003];

void dfs(int v, int p, int d){
    col[v] = d;
    for(const pii &x : adj[v]){
        if(x.fi == p) continue;
        dfs(x.fi, v, (d + x.se)&1);
    }
}

int main(){
	scanf("%d", &n);
    for(int i=1;i<n;++i){
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        --a, --b;
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }
    dfs(0, 0, 0);
    for(int i=0;i<n;++i){
        printf("%d\n", col[i]);
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