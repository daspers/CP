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
int cnt[400];

int main(){
    memset(cnt, 0 ,sizeof cnt);
    scanf("%d", &n);
    for(i=0;i<n;++i){
        int l, r;
        scanf("%d %d", &l, &r);
        cnt[l]++;
        cnt[r+1]--;
    }
    int ans = 0;
    for(i=1;i<=365;++i){
        cnt[i] += cnt[i-1];
        if(cnt[i]) ans++;
    }
    printf("%d\n", ans);
    return 0;
}