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
int a[100002][3];
vector<int> adj[100002];
ll dp[100002][4][4];

ll dfs(int v, int p, int lst1, int lst2){
    ll &ans = dp[v][lst1][lst2];
    if(ans == -1){
        if(adj[v].size()==1){
            ans = 1e9;
            for(int i=0;i<3;++i){
                if(lst1 != i &&  lst2 != i)
                    ans = min(ans, (ll)a[v][i]);
            }
        }
        else {
            ans = 1e18;
            for(int x : adj[v]){
                if(x != p){
                    for(int i=0;i<3;++i){
                        if(lst1 != i &&  lst2 != i)
                            ans = min(ans, dfs(x, v, i, lst1) + a[v][i]);
                    }
                }
            }
        }
    }
    return ans;
}

int arr[100002];
void print(int v, int p, int lst1, int lst2, ll target){
    if(adj[v].size() == 1){
        for(int i=0;i<3;++i){
            if(lst1 != i &&  lst2 != i && a[v][i] == target){
                arr[v] = i;
            }
        }
    }
    else {
        for(int x : adj[v]){
            if(x != p){
                for(int i=0;i<3;++i){
                    if(lst1 != i &&  lst2 != i){
                        if(dfs(x, v, i, lst1) + a[v][i] == target){
                            arr[v] = i;
                            print(x, v, i, lst1, target - a[v][i]);
                        }
                    }
                }
            }
        }
    }
}

int main(){
    memset(dp, -1, sizeof dp);
    scanf("%d", &n);
    for(int j=0;j<3;++j){
        for(int i=0;i<n;++i){
            scanf("%d", a[i]+j);
        }
    }
    for(int i=1;i<n;++i){
        int a, b;
        scanf("%d %d", &a, &b);
        --a, --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i=0;i<n;++i){
        if(adj[i].size() > 2){
            return puts("-1"), 0;
        }
    }
    ll ans = -1;
    int lol = 0;
    for(int i=0;i<n;++i){
        if(adj[i].size()==1){
            lol = i;
            ans = a[i][0] + dfs(adj[i][0], i, 0, 3);
            ans = min(ans, a[i][1] + dfs(adj[i][0], i, 1, 3));
            ans = min(ans, a[i][2] + dfs(adj[i][0], i, 2, 3));
            break;
        }
    }
    printf("%lld\n", ans);
    if(ans != -1){
        for(int i=0;i<3;++i){
            if(a[lol][i] + dfs(adj[lol][0], lol, i, 3) == ans){
                arr[lol] = i;
                print(adj[lol][0], lol, i, 3, ans-a[lol][i]);
            }
        }
    }
    for(int i=0;i<n;++i){
        printf("%d ", arr[i]+1);
    }
    puts("");
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