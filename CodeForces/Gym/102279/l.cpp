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
void printArray(const ll *arr, int n);
void printArray(const vector<int> &arr);

const ll mod = 1e9+7;
const double PI = acos(-1);

int n,i,j,k,t;
int l, r, c, u, v;
int a[100002];
ll ans[100002];
set<int> adj[100002];
vector<int> z;

int main(){
    memset(ans, -1, sizeof ans);
	scanf("%d %d %d %d", &n, &l, &r, &c);
	scanf("%d %d", &u, &v);
    --u; --v;
    for(int i=0;i<n;++i){
        scanf("%d", a+i);
        z.pb(a[i]);
    }
    sort(z.begin(), z.end());
    z.erase(unique(z.begin(), z.end()), z.end());
    for(int i=0;i<n;++i){
        a[i] = lower_bound(z.begin(), z.end(), a[i]) - z.begin();
        adj[a[i]].insert(i);
    }
    priority_queue<pair<ll, int>> pq;
    pq.push({0, v});
    while(!pq.empty()){
        pair<ll, int> tmp = pq.top();
        pq.pop();
        if(ans[tmp.se]!=-1 && ans[tmp.se] <= -tmp.fi) continue;
        adj[a[tmp.se]].erase(tmp.se);
        ans[tmp.se] = -tmp.fi;
        for(int x : adj[a[tmp.se]]){
            if(ans[x] != -1) continue;
            pq.push({tmp.fi - c, x});
        }
        adj[a[tmp.se]].clear();
        if(tmp.se > 0 && ans[tmp.se-1] == -1){
            pq.push({tmp.fi - r, tmp.se-1});
        }
        if(tmp.se < n-1 && ans[tmp.se+1] == -1){
            pq.push({tmp.fi - l, tmp.se+1});
        }
    }
    printf("%lld\n", ans[u]);
	return 0;
}

/* Template Function */
void printArray(const int * a, int n){
	for(int i=0;i<n;++i){
		printf("%d ", a[i]);
	}
	puts("");
}

void printArray(const ll * a, int n){
	for(int i=0;i<n;++i){
		printf("%lld ", a[i]);
	}
	puts("");
}

void printArray(const vector<int> &arr){
	for(int x : arr){
		printf("%d ", x);
	}
	puts("");
}