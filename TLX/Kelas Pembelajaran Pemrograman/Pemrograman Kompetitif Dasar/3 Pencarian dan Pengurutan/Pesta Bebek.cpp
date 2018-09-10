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
int a[1002];
string s[1002];
vector<int> ans;

int main(){
	FastSlowInput;
	cin>>n;
	for(i=0;i<n;++i){
		cin>>s[i];
		for(j=0;j<i;++j){
			// cout<<i<<" "<<s[i]<<" "<<s[j]<<endl;
			if(s[ans[j]] >= s[i])
				break;
		}
		ans.insert(ans.begin()+j, i);
		cout<<j+1<<"\n";
	}
	return 0;
}