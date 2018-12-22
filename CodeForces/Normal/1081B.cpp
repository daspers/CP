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
int b[100002];
int ans[100002];
vector<int> adj[100002];

int main(){
    scanf("%d", &n);
    for(i=0;i<n;++i){
        scanf("%d", b+i);
        adj[n-b[i]].pb(i);
    }
    int clock = 1;
    for(i=1;i<=n;++i){
        if(adj[i].size() == 0) continue;
        if(adj[i].size() % i) return puts("Impossible") & 0;
        int lim = adj[i].size() / i;
        for(j=0;j<lim;++j){
            for(k=0;k<i;++k){
                ans[adj[i][j*i+k]] = clock;
            }
            ++clock;
        }
    }
    puts("Possible");
    for(i=0;i<n;++i)
        printf("%d ", ans[i]);
    puts("");
    return 0;
}