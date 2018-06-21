#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define INF 200000001
#define EPS 1e-9

typedef long long ll;
typedef complex<double> cd;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;


int main(){
	scanf("%d %d", &n, &k);
	if(k==0)
		puts("0 0");
	else
		printf("%d %d\n", min(1, n-k), min(2*k, n-k));
	return 0;
}
