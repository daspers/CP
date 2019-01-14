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

const ll mod = 998244353 ;
const double PI = acos(-1);

int n,i,j,k,t;
int m;
int a[100002];
vector<int> c[100002];
char ans[100002];

int main(){
    memset(ans, '0', sizeof ans);
    scanf("%d %d", &n, &m);
    for(i=0;i<m;++i){
        scanf("%d", a+i);
        c[a[i]].pb(i);
    }
    int ma = c[1].size();
    for(i=2;i<=n;++i)
        ma = min(ma, (int)c[i].size());
    ans[m] = 0;
    for(i=0;i<ma;++i){
        int x = c[1][i];
        for(j=1;j<=n;++j){
            x = max(x, c[j][i]);
        }
        ans[x] = '1';
    }
    printf("%s", ans);
    return 0;
}