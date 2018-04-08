#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;

const ll mod = 1111111111;
const double pi = acos(-1);

struct matrix{
	void identity(){
		for(int i=0;i<103;i++){
			for(int j=0;j<103;j++){
				m[i][j] = 0;
			}
			m[i][i] = 1;
		}
	}
	void print(){
		for(int i=0;i<103;i++){
			for(int j=0;j<103;j++){
				printf("%lld ", m[i][j]);
			}
			puts("");
		}
	}
	void init(int *arr){
		memset(m, 0, sizeof m);
		m[0][0] = m[0][1] = 1;
		for(int i=2;i<103;i++)
			m[0][i] = arr[i-2];
		m[1][0] = 1;
		m[2][2] = 1;
		for(int i =3;i<103;i++){
			for(int j=2;j<=i;j++){
				m[i][j] = m[i-1][j-1] + m[i-1][j];
				m[i][j] %= mod;
			}
		}
	}
	friend matrix operator*(const matrix& a, const matrix& b){
		matrix res = a;
		for(int i=0;i<103;i++){
			for(int j=0;j<103;j++){
				res.m[i][j] = 0;
				for(int k=0;k<103;k++){
					res.m[i][j] += a.m[i][k]*b.m[k][j];
					res.m[i][j] %= mod;
				}
			}
		}
		return res;
	}
	ll m[103][103];
};

int n,t,j,i,k,m;
int arr[102];
int l,r;
ll p2[102];
matrix p[32];

ll sumfib(int n){
	if(n<=1)
		return 1;
	matrix res;
	res.identity();
	n--;
	for(int i=0;n;i++){
		if(n&1)
			res = res*p[i];
		n>>=1;
	}
	ll ans = (res.m[0][0] + res.m[0][1])%mod;
	for(int i=0;i<=m;i++){
		ans += (p2[i]*res.m[0][i+2])%mod;
		ans %= mod;
	}
	return ans;
}

int main(){
	p2[0] = 1;
	for(int i=1;i<=100;i++)
		p2[i] = (2*p2[i-1])%mod;
	memset(arr, 0, sizeof arr);
	scanf("%d %d", &n, &m);
	for(i=0;i<=m;i++){
		scanf("%d", arr+i);
	}
	p[0].init(arr);
	for(int i=1;i<32;i++){
		p[i] = p[i-1]*p[i-1];
	}
	ll ans = sumfib(n);
	printf("%lld\n", ans);
	return 0;
}