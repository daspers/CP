#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-5
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define debug2(a, b) cerr<<#a<<"="<<(a)<<" ";debug(b)
#define debug3(a, b, c) cerr<<#a<<"="<<(a)<<" ";debug2(b, c)
#define debug4(a, b, c, d) cerr<<#a<<"="<<(a)<<" ";debug3(b, c, d)
#define debug5(a, b, c, d, e) cerr<<#a<<"="<<(a)<<" ";debug4(b, c, d, e)
#define debug6(a, b, c, d, e, f) cerr<<#a<<"="<<(a)<<" ";debug5(b, c, d, e, f)
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<class T>
void printArray(const T * a, int n, ostream& out = cerr);
template<class T>
void printArray(const vector<T> &arr, ostream& out = cerr);

const ll mod = 1e9+7;
const double PI = acos(-1);

int n,i,j,k,t;
int m,s;
pii a[200002];
pii b[200002];

long double degToRad(long double a){return a*PI/180.0;}
long double radToDeg(long double a){return a*180.0/PI;}

struct point_i{
	int x,y;
	point_i(){x = 0; y=0;}
	point_i(int _x, int _y){x = _x; y = _y;}
};

struct point{
	long double x,y;
	point(){x = y = 0.0;}
	point(long double _x, long double _y): x(_x), y(_y){}
	bool operator < (point other) const {
		if(fabs(x-other.x)>EPS){return x < other.x;}
		return y<other.y;
	}
	bool operator == (point other){return ((fabs(x-other.x)<EPS) && (fabs(y-other.y)<EPS));}
};

ostream& operator<<(ostream& os, const point &pt){
	return os<<"("<<pt.x<<","<<pt.y<<")";
}

struct vec{
	long double x,y;
	vec(long double _x, long double _y): x(_x), y(_y){}
};

vec toVec(point a, point b){
	return vec(b.x-a.x, b.y-a.y);
}
long double dist(point p1, point p2){return hypot(p1.x-p2.x,p1.y-p2.y);}

long double perimeter(const vector<point> &P){
	long double result = 0.0;
	for(int i=0;i<P.size()-1;i++){
		result+=dist(P[i],P[i+1]);
	}
	return result;
}

long double area(const vector<point> &P){
	long double result = 0.0, x1,x2,y1,y2;
	for(int i=0;i<P.size()-1;i++){
		x1 = P[i].x; x2 = P[i+1].x;
		y1 = P[i].y; y2 = P[i+1].y;
		result+=(x1*y2 - x2*y1);
	}
	return fabs(result)/2.0;
}

long double dot(vec a, vec b){return (a.x*b.x + a.y*b.y);}
long double norm_sq(vec v){return (v.x*v.x + v.y*v.y);}

long double angle(point a, point o, point b){//return in rad
	vec oa = toVec(o,a), ob = toVec(o,b);
	return acos(dot(oa,ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

long double cross(vec a, vec b){return a.x*b.y - a.y*b.x;}
bool ccw(point p, point q, point r){
	return cross(toVec(p,q), toVec(p,r)) > 0;
}
bool collinear(point p, point q, point r){
	return fabs(cross(toVec(p,q), toVec(p,r))) < EPS;
}

bool isConvex(const vector<point> &P){
	int sz = P.size();
	if(sz <= 3){return false;}
	bool isLeft = ccw(P[0],P[1],P[2]);
	for(int i=1;i<sz-1;i++){
		if(ccw(P[i],P[i+1],P[(i+2)==sz? 1:i+2]) != isLeft){return false;}
	}
	return true;
}

bool inPolygon(point pt, const vector<point> &P){
	if(P.size()==0){return false;}
	long double sum = 0.0;
	for(int i=0;i<P.size()-1;i++){
		if(ccw(pt,P[i],P[i+1])){sum+=angle(P[i],pt,P[i+1]);}
		else{sum-=angle(P[i],pt,P[i+1]);}
	}
	return fabs(fabs(sum)-2*PI) <EPS;
}

point pivot;
bool angleCmp(point a, point b){
	if(collinear(pivot, a, b)){return dist(pivot,a) < dist(pivot,b);}
	point d1,d2;
	d1.x = a.x - pivot.x, d1.y = a.y - pivot.y;
	d2.x = b.x - pivot.x, d2.y = b.y - pivot.y;
	return (atan2(d1.y,d1.x) - atan2(d2.y,d2.x)) < 0;
}

vector<point> CH(vector<point> P) {
	int i,j, n =P.size();
	if(n<=3){
		if(!(P[0]==P[n-1])){P.pb(P[0]);}
		return P;
	}
	//find index so that P[idx] has lowest Y, if tie..the rightmost X
	int idx = 0;
	for(i=1;i<n;i++){
		if(P[i].y < P[idx].y || (P[i].y==P[idx].y && P[i].x > P[idx].x)){
			idx = i;
		}
	}
	//swap routine
	point temp = P[0]; P[0] = P[idx]; P[idx] = temp;
	//sort
	pivot = P[0];
	sort(++P.begin(),P.end(),angleCmp);

	vector<point> S;
	S.pb(P[n-1]); S.pb(P[0]); S.pb(P[1]);
	i = 2;
	while(i<n){
		j = S.size()-1;
		if(ccw(S[j-1],S[j],P[i])){S.pb(P[i++]);}
		else{S.pop_back();}
	}
	return S;
}

// line segment p-q intersect with line A-B.
point lineIntersectSeg(point p, point q, point A, point B) {
  long double a = B.y - A.y;
  long double b = A.x - B.x;
  long double c = B.x * A.y - A.x * B.y;
  long double u = fabs(a * p.x + b * p.y + c);
  long double v = fabs(a * q.x + b * q.y + c);
  return point((p.x * v + q.x * u) / (u+v), (p.y * v + q.y * u) / (u+v)); }

// cuts polygon Q along the line formed by point a -> point b
// (note: the last point must be the same as the first point)
vector<point> cutPolygon(point a, point b, const vector<point> &Q) {
  vector<point> P;
  for (int i = 0; i < (int)Q.size(); i++) {
    long double left1 = cross(toVec(a, b), toVec(a, Q[i])), left2 = 0;
    if (i != (int)Q.size()-1) left2 = cross(toVec(a, b), toVec(a, Q[i+1]));
    if (left1 > -EPS) P.push_back(Q[i]);       // Q[i] is on the left of ab
    if (left1 * left2 < -EPS)        // edge (Q[i], Q[i+1]) crosses line ab
      P.push_back(lineIntersectSeg(Q[i], Q[i+1], a, b));
  }
  if (!P.empty() && !(P.back() == P.front()))
    P.push_back(P.front());        // make P's first point = P's last point
  return P; }

ll cross(pii a, pii b){return 1LL*a.fi*b.se - 1LL*a.se*b.fi;}

pii toVec(pii a, pii b){
	return {b.fi-a.fi, b.se-a.se};
}
bool ccw(pii p, pii q, pii r){
	return cross(toVec(p,q), toVec(p,r)) > 0;
}
bool cw(pii p, pii q, pii r){
	return cross(toVec(p,q), toVec(p,r)) < 0;
}
bool point_in_segment(pii a, pii b, pii c){
	int dx = b.fi - c.fi;
	int dy = b.se - c.se;
	int g = __gcd(abs(dx), abs(dy));
	dx /= g;
	dy /= g;
	int ddx = a.fi - c.fi;
	int ddy = a.se - c.se;
	int gg = __gcd(abs(ddx), abs(ddy));
	return !(ddx != dx || ddy != dy || gg > g || gg < 0);
}

bool two_segment_intersect(pii a, pii b, pii c, pii d){
	if(point_in_segment(a, c, d) || point_in_segment(b, c, d) || point_in_segment(c, a, b) || point_in_segment(d, a, b)) return true;
	return ((ccw(a, b, c) &&  cw(a, b, d)) || (cw(a, b, c) &&  ccw(a, b, d))) && ((ccw(c, d, a) && cw(c, d, b)) || (cw(c, d, a) && ccw(c, d, b)));
}

int main(){
    scanf("%d %d", &n, &m);
	vector<point> va;
	vector<point> in;
	vector<pii> out;
    for(int i=0;i<n;++i){
		int x, y;
        scanf("%d %d", &x, &y);
		a[i] = {x, y};
		va.pb({x, y});
	}
	a[n] = a[0];
	va.pb(va.front());
	// printArray(a);
	// reverse(a.begin(), a.end());
    for(int i=0;i<m;++i){
        scanf("%d %d", &b[i].fi, &b[i].se);
		point pt(b[i].fi, b[i].se);
		if(inPolygon(pt, va)){
			in.pb(pt);
		}
		else {
			out.pb(b[i]);
		}
    }
	ll ans = 1LL*in.size()*((int)in.size()-1)/2;
	// ll next = 1LL*out.size()*((int)out.size()-1);
	// debug2(in.size(), out.size());
	for(int i=0;i<out.size();++i){
		for(int j=i+1;j<out.size();++j){
			int sum = 0;
			for(int k=1;k<=n;++k){
				if(point_in_segment(a[k], out[i], out[j])) continue;
				// point pt = lineIntersectSeg(out[i], out[j], a[k], a[k-1]);
				// debug(pt);
				// debug6(out[i], out[j], pt, dist(out[i], out[j]), dist(out[i], pt), dist(out[j], pt));
				// if(fabs(dist(out[i], out[j]) - dist(out[i], va[k]) - dist(out[j], va[k])) > EPS && (fabs(dist(va[k], va[k-1]) - dist(va[k], pt) - dist(va[k-1], pt)) > EPS || fabs(dist(out[i], out[j]) - dist(out[i], pt) - dist(out[j], pt)) > EPS )){
				if(!two_segment_intersect(out[i], out[j], a[k], a[k-1])){
					sum++;
				}
			}
			ans += sum == n;
		}
	}
	printf("%lld\n", ans);
    return 0;
}

/* Template Function */
template<class T>
void printArray(const T * a, int n, ostream& out){
    for(int i=0;i<n;++i){
        out<<a[i]<<" ";
    }
    out<<endl;
}

template<class T>
void printArray(const vector<T> &arr, ostream& out){
    for(const T& x : arr){
        out<<x<<" ";
    }
    out<<endl;
}