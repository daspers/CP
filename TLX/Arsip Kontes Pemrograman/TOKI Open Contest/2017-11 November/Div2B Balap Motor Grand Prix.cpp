#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

const double pi = acos(-1);
int n,i,j,k,l,r;
double a,b,kel,v,t,p;
vector<pair<double, int>> s;

int main(){
	scanf("%d %d %lf %lf", &n, &l, &a, &b);
	kel = pi*(a+b)*l/2;
	for(i=0;i<n;i++){
		scanf("%lf %lf", &v, &t);
		t += kel/v;
		s.pb({t,i});
	}
	sort(s.begin(), s.end());
	p=0;
	for(i=0;i<s.size();i++){
		if(s[i].fi != p){
			r = i+1;
			p = s[i].fi;
		}
		if(s[i].se == 0){
			printf("%d\n", r);
			return 0;
		}
	}
	return 0;
}
