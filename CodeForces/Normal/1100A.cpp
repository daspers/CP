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
int a[200];
int cnt[2];

int main(){
    memset(cnt, 0, sizeof cnt);
    scanf("%d %d", &n, &k);
    for(i=0;i<n;++i){
        scanf("%d", a+i);
        a[i] = max(a[i], 0);
        cnt[a[i]]++;
    }
    int ans = 0;
    for(i=0;i<k;++i){
        for(j=i;j<n;j+=k){
            cnt[a[j]]--;
        }
        ans = max(ans, abs(cnt[1] - cnt[0]));
        for(j=i;j<n;j+=k){
            cnt[a[j]]++;
        }
    }
    printf("%d\n", ans);
    return 0;
}