#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-8
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 998244353;
const double pi = acos(-1);

int n,i,j,k,t;


int main(){
	scanf("%d", &n);
	if(n%2==0){
		printf("%d\n", n-1);
		for(i=2;i<n;++i)
			printf("1 ");
		printf("2\n");
	}
	else{
		printf("2\n%d %d\n", n/2, (n+1)/2);
	}
	return 0;
}