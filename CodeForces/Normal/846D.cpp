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
int mep[501][501], s[501][501], m, q;
pair<int, pii> a[250002]; 
vector<int> cnt[501];

bool coba(int val){
	for(int i=0;i<m;++i){
		s[0][i] = 0; 
		for(int j=0;j<k;++j)
			s[0][i] += mep[j][i] > val;
		for(int j=1;j<=n-k;++j)
			s[j][i] = s[j-1][i] - (mep[j-1][i] > val) + (mep[j+k-1][i] > val);
	}
	for(int i=0;i<=n-k;++i){
		int tmp = 0;
		for(int j=0;j<k;++j)
			tmp += s[i][j];
		if(!tmp)
			return true;
		for(int j=k;j<m;++j){
			tmp += s[i][j] - s[i][j-k];
			if(!tmp)
				return true;
		}
	}
	return false;
}

int main(){
	scanf("%d %d %d %d", &n, &m, &k, &q);
	for(i=0;i<n;++i)
		for(j=0;j<m;++j)
			mep[i][j] = 1e9+2;
	for(i=0;i<q;++i){
		scanf("%d %d %d", &a[i].se.fi, &a[i].se.se, &a[i].fi);
		mep[--a[i].se.fi][--a[i].se.se] = a[i].fi;
	}
	sort(a, a+q);
	int l=0, r=1e9;
	while(l<r){
		int mid = (l+r)/2;
		if(coba(mid))
			r = mid;
		else
			l = mid+1;
	}
	printf("%d\n", coba(r)?r:-1);
	return 0;
}