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

const ll mod = 998244353;
const double PI = acos(-1);

int n,i,j,k,t;
int a[100002];
vector<ll> v;

int main(){
    for(i=1;i<=3162277;++i)
        v.pb(1LL*i*i);
    scanf("%d", &n);
    for(i=0;i<n/2;++i)
        scanf("%d", a+i);
    vector<ll> can;
    for(i=v.size()-1, j=n/2-1;i>=0 && j>=0;){
        // cout<<i<<" "<<j<<endl;
        int idx = lower_bound(v.begin(), v.end()+i, v[i]-a[j]) - v.begin();
        if(v[idx] != v[i] - a[j])
            --i;
        else{
            can.pb(v[i]);
            can.pb(v[idx]);
            i = idx-1;
            --j;
        }
    }
    if(j>=0)
        return puts("No") & 0;
    can.pb(0);
    reverse(can.begin(), can.end());
    puts("Yes");
    for(i=1;i<can.size();++i){
        printf("%lld ", can[i] - can[i-1]);
    }
    puts("");
	return 0;
}