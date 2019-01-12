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
ll c;
int h[200006];
ll dp[200006];

ostream& operator<<(ostream& out, pll x){
    out <<"("<<x.fi<<","<<x.se<<")";
    return out;
}

ll p2(ll val){
    return val*val;
}

ll f(pll curve, ll x){
    return p2(x - curve.fi) + curve.se;
}

double g(pll a, pll b){
    return 1.0*(p2(b.fi)+b.se-p2(a.fi)-a.se)/2/(b.fi-a.fi);
}

int main(){
    scanf("%d %lld", &n, &c);
    for(i=1;i<=n;++i)
        scanf("%d", h+i);
    deque<pll> curve;
    dp[1] = 0;
    curve.push_back({h[1], dp[1]+c});
    for(i=2;i<=n;++i){
        pll tmp = curve.front();
        curve.pop_front();
        while(!curve.empty()){
            if(f(tmp, h[i]) >= f(curve.front(), h[i])){
                tmp = curve.front();
                curve.pop_front();
            }
            else
                break;
        }
        dp[i] = f(tmp, h[i]);
        curve.push_front(tmp);
        tmp = {h[i], dp[i]+c};
        while(curve.size()>1){
            pll ttmp = curve.back();
            curve.pop_back();
            if(g(curve.back(), ttmp) < g(curve.back(), tmp)){
                curve.push_back(ttmp);
                break;
            }
        }
        curve.push_back(tmp);
    }
    printf("%lld\n", dp[n]);
    return 0;
}