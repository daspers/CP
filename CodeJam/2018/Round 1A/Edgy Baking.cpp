#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
 
const ll mod = 8;
const double pi = acos(-1);

struct rect{
	double w, h;
	double mic, mac;
	void proses(){
		mic = 2 * min(w,h);
		mac = 2*sqrt(w*w+h*h);
	}
	double perimeter(){
		return 2*w+2*h;
	}
};

int n,t,i,j,k;
double p;
rect a[101];
double dp[101][101];

int main(){
	scanf("%d", &t);
	for(int cc=1;t--;cc++){
		printf("Case #%d: ", cc);
		scanf("%d %lf", &n, &p);
		double cp = p;
		for(i=0;i<n;i++){
			scanf("%lf %lf", &a[i].w, &a[i].h);
			a[i].proses();
			cp -= a[i].perimeter();
		}
		double ma = a[0].mac;
		double mi = a[0].mic;
		if(double(ma * n) <= cp){
			cp -= ma*n;
		}
		else{
			if(mi <= cp){
				int a = cp/mi;
				int b = cp/ma;
				if(a>b){
					cp=0;
				}
				else{
					cp -= b*ma;
				}
			}
		}
		printf("%.8lf\n", p-cp);
	}
}