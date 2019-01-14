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

const ll mod = 998244353 ;
const double PI = acos(-1);

int n,i,j,k,t;
int r;

int main(){
    scanf("%d %d", &n, &r);
    double theta = 2*PI/n;
    double a = 2+2*cos(theta);
    double b = 4*r*(cos(theta) - 1);
    double c = r*r*2*(cos(theta) - 1);
    double x = -b/2/a;
    double y = sqrt(b*b - 4*a*c)/2/a;
    double R = x+y;
    printf("%.9lf\n", R);
    return 0;
}