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
ll len;
char s[50003];
int eq, ge, le;

int intlog2(ll val){
	return val? 1 + intlog2(val/2) : 0;
}

int main(){
	ll n, k;
	scanf("%lld %lld", &n, &k);
	scanf("%s", s);
	len = strlen(s);
	eq=ge=le=0;
	for(i=0;i<len;++i){
		if(s[i] == '<')
			le++;
		else if(s[i]=='>')
			ge++;
		else
			eq++;
	}
	if(le+ge >= n || len > n)
		return puts("-1") & 0;
	if(eq){
		if(intlog2(n)> len)
			return puts("-1") & 0;
		vector<ll> ans;
		ll l = 1, r = n;
		for(i=0;i<len-1;++i){
			ll kiri, kanan;
			kiri = kanan = (r-l+1)/2;
			if((l-r-1)&1)
				++kanan;
			kiri = max(kiri, len-i-1);
			kanan = max(kanan, len-i-1);
			if(s[i] == '>'){
				ans.pb(r - kanan);
				l = r - kanan + 1;
			}
			else{
				ans.pb(l + kiri);
				r = l + kiri - 1;
			}
		}
		if(l < r)
			return puts("-1") & 0;
		ans.pb(l);
		for(i=0;i<ans.size();++i){
			if(i) printf(" ");
			printf("%lld", ans[i]);
		}
		puts("");
	}
	else{
		ll l = 1, r = n;
		for(i=0;i<len;++i){
			if(i) printf(" ");
			if(s[i]=='>')
				printf("%lld", l++);
			else
				printf("%lld", r--);
		}
		puts("");
	}
	return 0;
}