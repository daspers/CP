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

struct pt {
    double x, y;
    pt(double x, double y):x(x), y(y){}
    pt(){}
};

bool cmp(pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull(vector<pt>& a) {
    if (a.size() == 1)
        return;

    sort(a.begin(), a.end(), &cmp);
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
}

ll area(pll a, pll b, pll c){
    ll ans = 1LL*(a.fi - c.fi)*(b.se - a.se) - 1LL*(a.fi - b.fi)*(c.se - a.se);
    return llabs(ans);
}

int main(){
    scanf("%d", &n);
    vector<pt> p;
    vector<pii> v;
    for(i=0;i<n;++i){
        int a, b;
        scanf("%d %d", &a, &b);
        p.pb({(double)a, (double)b});
    }
    convex_hull(p);
    n = p.size();
    if(n < 3)
        return puts("0")&1;
    for(i=0;i<n;++i)
        v.pb({(int)p[i].x, (int)p[i].y});
    ll ans = 0;
    for(i=0;i<n-2;++i){
        for(j=i+2;j<n;++j){
            int l,r;
            l = i+1;
            r = j-1;
                ans = max(ans, area(v[i], v[j], v[l]));
            if(l < r){
                ans = max(ans, area(v[i], v[j], v[r]));
                while(l + 1 < r){
                    int mid = (l+r)/2;
                    ll al = area(v[i], v[j], v[mid]);
                    ll ar = area(v[i], v[j], v[mid+1]);
                    if(al < ar)
                        l = mid;
                    else
                        r = mid;
                }
                ans = max(ans, area(v[i], v[j], v[l+1]));
            }
        }
    }
    printf("%lld", ans/2);
    if(ans & 1)
        puts(".5");
    else
        puts("");
    return 0;
}