#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,t,j,i,k,m;
int id1, id2;
ll jmi;
pair<int, pair<ll, ll>> p[50005];

void hitung(int a, int b){
	if(a>b)
		swap(a,b);
	ll dx = p[a].se.fi-p[b].se.fi;
	ll dy = p[a].se.se-p[b].se.se;
	ll temp = dx*dx + dy*dy;
	if(temp < jmi){
		jmi = temp;
		id1 = p[a].fi;
		id2 = p[b].fi;
	}
}

void getmin(int l, int r){
	if(l==r)
		return;
	if(l+1==r){
		hitung(l, r);
		return;
	}
	int mid = (l+r)>>1;
	getmin(l, mid);
	getmin(mid+1, r);
	for(int i=mid;i>=l&&p[mid+1].se.fi-p[i].se.fi<jmi;i--){
		for(int j=mid+1;j<=r&&p[j].se.fi-p[mid].se.fi<jmi;j++){
			hitung(i, j);
		}
	}
}

int main(){
	jmi=1e18;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%lld %lld", &p[i].se.fi, &p[i].se.se);
		p[i].fi = i;
	}
	sort(p, p+n, [](const pair<int, pair<ll, ll>>& a, const pair<int, pair<ll, ll>>& b){
		if(a.se.fi!=b.se.fi)
			return a.se.fi < b.se.fi;
		return a.se.se < b.se.se;
	});
	getmin(0, n-1);
	if(id1>id2)
		swap(id1, id2);
	printf("%d %d %.6Lf\n", id1, id2, sqrtl(jmi));
	return 0;
}