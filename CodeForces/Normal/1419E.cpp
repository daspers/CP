#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-9
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define debug2(a, b) cerr<<#a<<"="<<(a)<<" ";debug(b)
#define debug3(a, b, c) cerr<<#a<<"="<<(a)<<" ";debug2(b, c)
#define debug4(a, b, c, d) cerr<<#a<<"="<<(a)<<" ";debug3(b, c, d)
#define debug5(a, b, c, d, e) cerr<<#a<<"="<<(a)<<" ";debug4(b, c, d, e)
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<class T>
void printArray(const T * a, int n, ostream& out = cerr);
template<class T>
void printArray(const vector<T> &arr, ostream& out = cerr);

const ll mod = 1e9+7;
const double PI = acos(-1);

int n,i,j,k,t;
vector<int> adj[10000];
bool vis[10000];
int last = 0;
vector<int> v;

void dfs(int u){
    last = v[u];
    printf("%d ", v[u]);
    for(int x : adj[u]){
        if(vis[x]) continue;
        vis[x] = true;
        dfs(x);
        break;
    }
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int sq = sqrt(n);
        for(int i=1;i<=sq;++i){
            if(n % i == 0){
                v.pb(i);
                if(n/i != i){
                    v.pb(n/i);
                }
            }
        }
        sort(v.begin(), v.end());
        int ans = 0;
        for(int i=1;i<v.size();++i) {
            for(int j=i+1;j<v.size();++j){
                if(__gcd(v[i], v[j]) > 1) {
                    adj[i].pb(j);
                    adj[j].pb(i);
                }
            }
        }
        memset(vis, false, sizeof vis);
        vis[1] = true;
        dfs(1);
        puts("");
        puts(__gcd(last, v[1]) > 1 ? "0" : "1");
        for(int i=0;i<v.size();++i){
            adj[i].clear();
        }
        v.clear();
    }
    return 0;
}

/* Template Function */
template<class T>
void printArray(const T * a, int n, ostream& out){
    for(int i=0;i<n;++i){
        out<<a[i]<<" ";
    }
    out<<endl;
}

template<class T>
void printArray(const vector<T> &arr, ostream& out){
    for(const T& x : arr){
        out<<x<<" ";
    }
    out<<endl;
}