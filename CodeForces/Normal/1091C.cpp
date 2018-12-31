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

int main(){
	scanf("%d", &n);
    vector<ll> ans;
    int sq = sqrt(n);
    for(int i=1;i<=sq;++i){
        if(n % i == 0){
            int num = (n - 1)/i + 1;
            int fin = 1 + (num-1)*i;
            ans.pb(1LL*num * (fin + 1)/2);
            // cout<<i<<" "<<num<<" "<<fin<<" "<<num/2LL * (fin + 1) + 1<<endl;
            if(n/i != i){
                num = (n - 1)/(n/i) + 1;
                fin = 1 + (num-1)*(n/i);
                ans.pb(1LL*num* (fin + 1)/2);
            }
        }
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for(ll x : ans){
        printf("%lld ", x);
    }
    puts("");
	return 0;
}