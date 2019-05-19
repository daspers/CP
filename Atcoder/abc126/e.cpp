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
vector<int> adj[100002];
int par[100002];

int find_set(int v){
    if(v == par[v])
        return v;
    return par[v] = find_set(par[v]);
}

bool union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        par[b] = a;
        return true;
    }
    return false;
}

int main(){
	scanf("%d %d", &n, &m);
    for(int i=0;i<n;++i)
        par[i] = i;
    int ans = n;
    for(int i=0;i<m;++i){
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        --a, --b;
        adj[a].pb(b);
        adj[b].pb(a);
        if(union_set(a, b)){
            ans--;
        }
    }
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