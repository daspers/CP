#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;

const ll mod = 1e9+7;
const double pi = acos(-1);

struct matrix{
	void identity(){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				m[i][j] = 0;
			}
		}
		m[0][0] = m[1][1]=m[2][2] = 1;
	}
	void init(){
		m[1][0] = m[2][0] = m[2][2] = 0;
		m[0][0] = m[0][1] = m[0][2] = 1;
		m[1][1] = m[1][2] = 1;
		m[2][1] = 1;
	}
	friend matrix operator*(const matrix& a, const matrix& b){
		matrix res = a;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				res.m[i][j] = 0;
				for(int k=0;k<3;k++){
					res.m[i][j] += a.m[i][k]*b.m[k][j];
					res.m[i][j] %= mod;
				}
			}
		}
		return res;
	}
	ll m[3][3];
};

int n,t,j,i,k,m;
int l,r;
matrix p[32];

ll sumfib(int n){
	if(n<=2)
		return n>0?n:0;
	matrix res;
	res.identity();
	n-=1;
	for(int i=0;n;i++){
		if(n&1)
			res = res*p[i];
		n>>=1;
	}
	return (res.m[0][0] + res.m[0][1])%mod;
}

int main(){
	p[0].init();
	for(int i=1;i<32;i++){
		p[i] = p[i-1]*p[i-1];
	}
	scanf("%d\n", &t);
	while(t--){
		scanf("%d %d", &l, &r);
		ll ans =  (sumfib(r) - sumfib(l-1)) % mod;
		if(ans<0){
			ans += mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}