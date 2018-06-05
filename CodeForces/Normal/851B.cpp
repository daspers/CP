#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define INF 200000001
#define EPS 1e-9

typedef long long ll;
typedef complex<double> cd;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n, i,j,k,t;

int main(){
	ll a,b,c,d,e,f;
	scanf("%lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f);
	ll ac, ae, ce;
	ac = (a-c)*(a-c)+(b-d)*(b-d);
	ae = (a-e)*(a-e)+(b-f)*(b-f);
	ce = (c-e)*(c-e)+(d-f)*(d-f);
	// cout<<ac<<" "<<ae<<" "<<ce<<endl;
	if(ac==ce && ae != 4*ac)
		puts("YES");
	else
		puts("NO");
	return 0;
}
