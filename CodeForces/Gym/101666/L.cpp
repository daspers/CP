#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-8
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define FastSlowInput ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
long double ma[200002];
bool defined[200002];
pair<pii, long double> a[100002];
map<string, int> mep;
string s, r;
int len;

int main(){
	memset(defined, false, sizeof defined);
	FastSlowInput;
	mep["pink"] = 0;
	mep["blue"] = 1;
	memset(ma, 0, sizeof ma);
	cin>>n;
	len = 2;
	for(i=0;i<n;++i){
		long double w;
		cin>>s>>r>>w;
		if(!mep.count(s))
			mep[s] = len++;
		if(!mep.count(r))
			mep[r] = len++;
		a[i] = {{mep[r], mep[s]}, w};
	}
	ma[0] = 0;
	defined[0] = true;
	for(i=0;i<n;++i){
		if(!defined[a[i].fi.fi])
			continue;
		if(defined[a[i].fi.se])
			ma[a[i].fi.se] = max(ma[a[i].fi.se], log10(a[i].se) + ma[a[i].fi.fi]);
		else
			ma[a[i].fi.se] = log10(a[i].se) + ma[a[i].fi.fi];
		defined[a[i].fi.se] = true;
	}
	if(defined[1]){
		cout<<setprecision(9)<<fixed;
		if(ma[1]>=1)
			cout<<"10.0\n";
		else
			cout<<pow(10, ma[1])<<endl;
	}
	else
		cout<<"0.0\n";
	return 0;
}
