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
int a[200002];
int cnt[200002];
int deg[200002];
vector<int> adj[200002];
vector<int> mapper;
bool vis[200002];
int p2[33];

int main(){
    p2[0] = 1;
    for(i=1;i<=31;++i)
        p2[i] = 2*p2[i-1];
    memset(cnt, 0, sizeof cnt);
    memset(vis, false, sizeof vis);
    scanf("%d", &n);
    multiset<int> s;
    for(i=0;i<n;++i){
        scanf("%d", a+i);
        mapper.pb(a[i]);
        s.insert(a[i]);
    }
    sort(mapper.begin(), mapper.end());
    mapper.erase(unique(mapper.begin(), mapper.end()), mapper.end());
    for(i=0;i<n;++i){
        ++cnt[lower_bound(mapper.begin(), mapper.end(), a[i]) - mapper.begin()];
    }
    for(i=0;i<mapper.size();++i){
        for(j=0;j<=30;++j){
            if(p2[j] <= 2 * mapper[i]) continue;
            int idx = lower_bound(mapper.begin(), mapper.end(), p2[j] - mapper[i]) - mapper.begin();
            if(idx < mapper.size() && mapper[idx] + mapper[i] == p2[j]){
                adj[i].pb(idx);
                adj[idx].pb(i);
                deg[i]++;
                deg[idx]++;
            }
        }
    }
    queue<int> q;
    for(i=0;i<mapper.size();++i){
        int idx = lower_bound(p2, p2+31, mapper[i]) - p2;
        if(deg[i] == 1 && mapper[i] != p2[idx]){
            q.push(i);
        }
    }
    int ans = 0;
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        if(vis[tmp]) continue;
        vis[tmp] = true;
        for(int x : adj[tmp]){
            if(vis[x]) continue;
            int val = min(cnt[tmp], cnt[x]);
            ans += val;
            cnt[tmp] -= val;
            cnt[x] -= val;
            if(--deg[x] == 1)
                q.push(x);
            break;
        }
    }
    for(i=0;i<mapper.size();++i){
        int idx = lower_bound(p2, p2+31, mapper[i]) - p2;
        if(mapper[i] != p2[idx]) continue;
        if(vis[i]){
            ans += cnt[i]/2;
            cnt[i] &= 1;
        }
        else if(deg[i] == 1){
            q.push(i);
        }
        else{
            ans += cnt[i]/2;
            cnt[i] &= 1;
        }
    }
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        if(vis[tmp]) continue;
        vis[tmp] = true;
        for(int x : adj[tmp]){
            if(vis[x]) continue;
            int val = min(cnt[tmp], cnt[x]);
            ans += val;
            cnt[tmp] -= val;
            cnt[x] -= val;
            if(--deg[x] == 1)
                q.push(x);
            break;
        }
        if(cnt[tmp]){
            ans += cnt[tmp]/2;
            cnt[tmp] &= 1;
        }
    }
    printf("%d\n", ans);
	return 0;
}