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
map<string, string> mep;
string s, r;

int main(){
	// scanf("%d %d", &n, &k);
	FastSlowInput;
	cin>>n>>k;
	for(i=0;i<n;++i){
		cin>>s>>r;
		mep[s] = r;
	}
	for(i=0;i<k;++i){
		cin>>s;
		if(mep.count(s))
			cout<<mep[s]<<"\n";
		else
			cout<<"NIHIL\n";
	}
	return 0;
}