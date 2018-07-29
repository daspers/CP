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

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;

int main(){
	int a[3];
	scanf("%d %d %d", a, a+1, a+2);
	sort(a, a+3);
	if(a[2]%4){
		puts("TIDAK");
		return 0;
	}
	int t = a[2]/4;
	if(max(a[0], a[1]) > t*2 || a[0]+a[1] != t*3)
		puts("TIDAK");
	else
		puts("YA");
	return 0;
}