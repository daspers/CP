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
int x[1002], y[1002];

int main(){
	scanf("%d", &n);
    map<pii, int> cnt;
    for(i=0;i<n;++i){
        scanf("%d %d", x+i, y+i);
    }
    for(i=0;i<n;++i){
        int a, b;
        scanf("%d %d", &a, &b);
        for(j=0;j<n;++j){
            cnt[{x[j]+a, y[j]+b}]++;
        }
    }
    for(const pair<pii, int> &x : cnt){
        if(x.se == n){
            printf("%d %d\n", x.fi.fi, x.fi.se);
            return 0;
        }
    }
    return -192929;
	return 0;
}