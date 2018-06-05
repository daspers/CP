#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define Nmax 300000 
#define EPS 1e-9

typedef long long ll;
typedef complex<double> cd;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t,m;
int a[200003];

int main(){
	scanf("%d", &t);
	for(int cc =1; cc<=t;++cc){
		printf("Case #%d: ", cc);
		scanf("%d", &n);
		for(i=0;i<n;++i)
			scanf("%d", a+i);
		a[n] = 0;
		for(i=n;i>0;--i){
			a[i] -= a[i-1];
		}
		vector<pair<int, int>> awal, akhir;
		for(i=0;i<=n;++i){
			if(a[i] > 0)
				awal.pb({i, a[i]});
			else if(a[i]<0)
				akhir.pb({i, -a[i]});
		}
		bool bisa = true;
		for(i=j=0;i<awal.size()&&j<akhir.size();){
			if(akhir[j].fi - awal[i].fi < 3 ){
				bisa = false;
				break;
			}
			int tmp = min(awal[i].se, akhir[j].se);
			awal[i].se -= tmp;
			akhir[j].se -= tmp;
			if(awal[i].se==0)
				i++;
			if(akhir[j].se==0)
				j++;
		}
		if(bisa && i==awal.size() && j==akhir.size())
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}