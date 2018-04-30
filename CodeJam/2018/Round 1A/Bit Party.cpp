#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
 
const ll mod = 8;
const double pi = acos(-1);

struct kasir{
	ll m,s,p;
	double avgtime;
	void proses(){
		avgtime = 1.0*m*s + p/s;
	}
};

int n,t,i,j,k;
int r,b,c;
ll mi;
kasir a[1002];

void btck(int idx, int robot, int rem, ll waktu){
	if(idx == c){
		if(rem==0){
			mi = min(mi, waktu);
		}
		return;
	}
	else if(rem==0){
		mi = min(mi, waktu);
		return;
	}
	else if(robot==0)
		return;
	for(int i=0;i<=rem&&i<=a[idx].m;i++){
		ll hit = a[idx].s*i+ a[idx].p*(i>0);
		btck(idx+1, robot-(i>0), rem-i, max(waktu,  hit));
	}
}

int main(){
	scanf("%d", &t);
	for(int cc=1;t--;cc++){
		printf("Case #%d: ", cc);
		scanf("%d %d %d", &r, &b, &c);
		for(i=0;i<c;i++){
			scanf("%lld %lld %lld", &a[i].m, &a[i].s, &a[i].p);
			a[i].proses();
		}
		mi = 2e18;
		btck(0, r, b, 0);
		printf("%lld\n", mi);
	}
	return 0;
} 