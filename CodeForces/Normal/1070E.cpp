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
int m;
ll tl;
int a[200002];

int coba(int val){
    int num = 0;
    ll totm = 0;
    ll curr = 0;
    for(int i=0;i<n;++i){
        if(a[i] > val)
            continue;
        if(totm + a[i] > tl)
            break;
        totm += a[i];
        curr += a[i];
        num++;
        if(num % m == 0){
            totm += curr;
            curr = 0;
            if(totm > tl)
                break;
        }
    }
    return num;
}

int main(){
    int tc;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d %d %lld", &n, &m, &tl);
        vector<int> v;
        for(i=0;i<n;++i){
            scanf("%d", a+i);
            v.pb(a[i]);
        }
        int ans = 1;
        ll ma = 0;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        int l = 0, r, c;
        if(tl > 2e5)
            r = v.size()-1;
        else
            r = upper_bound(v.begin(), v.end(), tl) - v.begin()-1;
        c = coba(v[l]);
        if(c > ma){
            ma = c;
            ans = v[l];
        }
        c = coba(v[r]);
        if(c > ma){
            ma = c;
            ans = v[r];
        }
        while(l + 2 < r){
            int diff = (r-l)/3;
            int ql = l+diff;
            int qr = r-diff;
            ll c1 = coba(v[ql]);
            ll c2 = coba(v[qr]);
            if(c1 > ma){
                ma = c1;
                ans = v[ql];
            }
            if(c2 > ma){
                ma = c2;
                ans = v[qr];
            }
            if(c1 < c2)
                l = ql;
            else
                r = qr;
        }
        if(r-l > 1){
            c = coba(v[l+1]);
            if(c > ma){
                ma = c;
                ans = v[l+1];
            }
            c = coba(v[r-1]);
            if(c > ma){
                ma = c;
                ans = v[r-1];
            }
        }
        printf("%lld %d\n", ma, ans);
    }
    return 0;
}