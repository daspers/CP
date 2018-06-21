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

int n,i,j,k,t;
string s;
int a[300002], b[300002];

int main(){
	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
	scanf("%d", &n);
	for(i=0;i<n;++i){
		cin>>s;
		int lw=0, rw=0;
		for(char c : s){
			if(c==')'){
				if(lw==0)
					rw++;
				else
					lw--;
			}
			else
				lw++;
		}
		if(!lw||!rw){
			if(rw)
				b[rw]++;
			else
				a[lw]++;
		}
	}
	ll ans = 0;
	if(a[0]>0)
		ans += 1LL*a[0]*a[0];
	for(i=1;i<300001;++i)
		ans += 1LL*a[i]*b[i];
	printf("%lld\n", ans);
	return 0;
}
