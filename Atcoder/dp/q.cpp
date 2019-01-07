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
int h[200004];
int a[200004];
ll dp[200004];
ll tree[800005];

void update(int l, int r, int pos, int idx, ll val){
    if(r < idx || l > idx)
        return;
    if(l == r){
        tree[pos] = max(tree[pos], val);
        return;
    }
    int mid = (l+r)>>1;
    update(l, mid, 2*pos+1, idx, val);
    update(mid+1, r, 2*pos+2, idx, val);
    tree[pos] = max(tree[2*pos+1], tree[2*pos+2]);
}

ll query(int l, int r, int pos, int ql){
    if(r < ql)
        return 0;
    if(l >= ql)
        return tree[pos];
    int mid = (l+r)/2;
    return max(query(l, mid, 2*pos+1, ql), query(mid+1, r, 2*pos+2, ql));
}

int main(){
    memset(tree, 0, sizeof tree);
    scanf("%d", &n);
    for(i=1;i<=n;++i)
        scanf("%d", h+i);
    for(i=1;i<=n;++i)
        scanf("%d", a+i);
    for(i=n;i>=1;--i){
        dp[i] = a[i] + query(1, n, 0, h[i]);
        update(1, n, 0, h[i], dp[i]);
    }
    printf("%lld\n", query(1, n, 0, 1));
    return 0;
}