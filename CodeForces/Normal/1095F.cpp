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
int m;
ll a[200003];
set<pair<ll, int> > v;
int par[200002];
ll ans = 0;

int find_set(int v){
    if(v == par[v]){
        return v;
    }
    return par[v] = find_set(par[v]);
}

bool union_set(int b, int c){
    c = find_set(c);
    b = find_set(b);
    if(c != b){
        if(a[b] < a[c])
            par[c] = b;
        else
            par[b] = c;
        return true;
    }
    return false;
}

int main(){
    scanf("%d %d", &n, &m);
    for(i=1;i<=n;++i){
        scanf("%lld", a+i);
        v.insert({a[i], i});
        par[i] = i;
    }
    vector<pair<ll, pii> > w;
    for(i=0;i<m;++i){
        int x,y;
        ll z;
        scanf("%d %d %lld", &x, &y, &z);
        w.pb({z, {x, y}});
    }
    sort(w.begin(), w.end());
    int curr = v.begin()->se;
    v.erase(v.begin());
    for(j=0;v.size() > 0;){
        set<pair<ll, int> >::iterator it = v.begin(), ot;
        ll lol = a[curr] + it->fi;
        if(j < w.size() && lol >= w[j].fi){
            if(union_set(w[j].se.fi, w[j].se.se)){
                ans += w[j].fi;
                if(find_set(w[j].se.fi) != w[j].se.fi){
                    ot = v.find({a[w[j].se.fi], w[j].se.fi});
                    if(ot != v.end())
                        v.erase(ot);
                }
                if(find_set(w[j].se.se) != w[j].se.se){
                    ot = v.find({a[w[j].se.se], w[j].se.se});
                    if(ot != v.end())
                        v.erase(ot);
                }
            }
            ++j;
        }
        else{
            if(union_set(curr, it->se)){
                ans += lol;
            }
            v.erase(v.begin());
        }
    }
    printf("%lld\n", ans);
	return 0;
}