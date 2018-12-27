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
int a[500002];
int cntc[500002];
vector<int> idx[500002];

int main(){
    cntc[0] = 0;
    scanf("%d %d", &n, &k);
    int ans = 0;
    for(i=1;i<=n;++i){
        scanf("%d", a+i);
        idx[a[i]].pb(i);
        cntc[i] = (a[i]==k) + cntc[i-1];
    }
    for(i=1;i<=500000;++i){
        if(i == k || idx[i].size() == 0) continue;
        vector<int> &v = idx[i];
        int cnt = 1;
        int now = 1;
        for(j=1;j<v.size();++j){
            if(cnt > cntc[v[j]] - cntc[v[j-1]])
                cnt += 1 - (cntc[v[j]] - cntc[v[j-1]]);
            else
                cnt = 1;
            now = max(now, cnt);
        }
        ans = max(ans, now);
    }
    printf("%d\n", cntc[n] + ans);
    return 0;
}