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
string s;
string enc[] = {"ei", "bi", "si", "di", "i", "ef", "dei",
	"eitf", "ai", "djei", "kei", "el", "em", "en", "ou", "pi",
"kiu", "ar", "es", "ti", "ju", "vi", "dabelju", "eks", "wai", "zi"};

int main(){
	getline(cin, s);
	for(char c : s){
		if(c<'a' || c>'z')
			cout<<c;
		else
			cout<<enc[c-'a'];
	}
	cout<<"\n";
	return 0;
}