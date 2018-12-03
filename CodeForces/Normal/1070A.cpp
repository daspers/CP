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

const int maxn = 560;
int n,i,j,k,t;
int d, s;
// map<pii, int> dp[maxn];
int p[maxn];
bool vis[501][5001];

int main(){
    memset(vis, 0, sizeof vis);
    scanf("%d %d", &d, &s);
    queue<pair<pii, string>> q;
    for(i=1;i<=min(9, s);++i){
        string ss = "";
        q.push({{i%d, i}, ss+char(i+'0')});
    }
    while(!q.empty()){
        pair<pii, string> tmp = q.front();
        q.pop();
        if(tmp.se.size() >= 560) break;
        if(tmp.fi.fi == 0 && tmp.fi.se == s){
            cout<<tmp.se<<endl;
            exit(0);
        }
        for(i=0;i<=min(9, s-tmp.fi.se);++i){
            if(vis[(tmp.fi.fi*10+i)%d][tmp.fi.se+i]) continue;
            vis[(tmp.fi.fi*10+i)%d][tmp.fi.se+i] = true;
            q.push({{(tmp.fi.fi*10+i)%d, tmp.fi.se+i}, tmp.se+char(i+'0')});
        }
    }
    cout<<-1<<endl;
    return 0;
}