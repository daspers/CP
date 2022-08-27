#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll mod = 1e9+7;
const double PI = acos(-1);

struct point{
	long long x,y;
	point(){x = y = 0.0;}
	point(long long _x, long long _y): x(_x), y(_y){}
	bool operator < (point other) const {
		if (x != other.x) { return x < other.x; }
		return y<other.y;
	}
	bool operator == (point other) { return (x == other.x && y == other.y); }
};

ostream& operator<<(ostream& os, const point &pt){
	return os<<"("<<pt.x<<","<<pt.y<<")";
}

long long dist(point p1, point p2) { return hypot(p1.x - p2.x, p1.y - p2.y); }

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(point p, point q, point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

bool inPolygon(point pt, const vector<point> &P) {
	if (P.size() <= 2) { return false; }
    int firstOrientation = orientation(pt, P[0], P[1]);
    int np = P.size();
	for (int i = 1; i < np; i++) {
		if (orientation(pt, P[i], P[(i + 1) % np]) != firstOrientation) return false;
	}
    return true;
}

// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(point p, point q, point r) {
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;
    return false;
}

bool doIntersect(point p1, point q1, point p2, point q2) {
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4) return true;

    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    // p1, q1 and q2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
     // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false; // Doesn't fall in any of the above cases
}

int n, m;

int main(){
    scanf("%d %d", &n, &m);
	vector<point> a, b, in, out;
    for(int i=0;i<n;++i){
		long long x, y;
        scanf("%lld %lld", &x, &y);
		a.pb({x, y});
	}

    for (int i = 0; i < m; ++i) {
		long long x, y;
        scanf("%lld %lld", &x, &y);
        point pt = point(x, y);
        b.pb({x, y});

		if (inPolygon(pt, a))   in.pb(pt);
		else                    out.pb(pt);
    }

	ll ans = 1LL * in.size() * ((int) in.size() - 1) / 2;

	for (int i = 0; i < out.size(); ++i) {
		for (int j = i + 1; j < out.size(); ++j) {
			bool isIntersect = false;
			for (int k = 1; k < a.size() && !isIntersect; ++k) {
				if (doIntersect(a[k - 1], a[k], out[i], out[j])) {
                    isIntersect = true;
                }
			}
            // printf("(%lld,%lld) x (%lld,%lld) : %d\n", out[i].x, out[i].y, out[j].x, out[j].y, isIntersect);
			if (!isIntersect) ans++;
		}
	}
	printf("%lld\n", ans);
    return 0;
}
