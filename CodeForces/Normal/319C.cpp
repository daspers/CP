#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-8
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9+7;
const double pi = acos(-1);

typedef long double ftype;
typedef complex<ftype> point;
#define x real
#define y imag

ftype dot(point a, point b) {
    return (conj(a) * b).x();
}

ftype cross(point a, point b) {
    return (conj(a) * b).y();
}

int n,i,j,k,t;
pll a[100002];
vector<point> hull, vecs;

void add_line(ftype k, ftype b) {
    point nw = {k, b};
    while(!vecs.empty() && dot(vecs.back(), nw - hull.back()) > 0) {
        hull.pop_back();
        vecs.pop_back();
    }
    if(!hull.empty())
        vecs.push_back(point(0, 1) * (nw - hull.back()));
    hull.push_back(nw);
}

ftype get(ftype x) {
	if(hull.size()==0)
		return 0;
    point query = {x, 1};
    auto it = lower_bound(vecs.begin(), vecs.end(), query, [](point a, point b) {
        return cross(a, b) > 0;
    });
    return dot(query, hull[it - vecs.begin()]);
}

int main(){
	scanf("%d", &n);
	for(i=0;i<n;++i)
		scanf("%lld", &a[i].fi);
	for(i=0;i<n;++i)
		scanf("%lld", &a[i].se);
	if(n==1){
		puts("0");
		return 0;
	}
	for(i=0;i<n-1;++i)
		add_line(a[i].se, get(a[i].fi));
	printf("%.0Lf\n", get(a[n-1].fi));
	return 0;
}