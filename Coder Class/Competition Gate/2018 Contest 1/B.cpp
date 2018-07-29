#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-9
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;

const ll mod = 1e9+7;
const double PI = acos(-1);

int n,i,j,k,t;
unsigned long long bit[65];

ull xors(ull n){
	if(n%4==1)
		return 1;
	else if(n%4==2)
		return n+1;
	else if(n%4==3)
		return 0;
	else
		return n;
}

int main(){
	memset(bit, 0, sizeof bit);
	ull a, b;
	scanf("%llu %llu", &a, &b);
	ull ans = xors(b)^xors(a-1);
	for(i=0;ans;++i){
		if(ans&1)
			bit[i]++;
		ans>>=1LLU;
	}
	for(i=63;i>=0;--i){
		if(bit[i]&1)
			break;
	}
	if(i<0)
		puts("0");
	else{
		while(i>=0)
			printf("%llu", bit[i--]&1);
		puts("");
	}
	return 0;
}