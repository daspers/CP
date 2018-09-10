#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-8
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
string s[502];

int main(){
	FastSlowInput;
	cin>>n;
	for(i=0;i<n;++i)
		cin>>s[i];
	sort(s, s+n, [](const string &a, const string &b){
		if(a.size() == b.size())
			return a < b;
		return a.size() < b.size();
	});
	for(i=0;i<n;++i)
		cout<<s[i]<<"\n";
	return 0;
}