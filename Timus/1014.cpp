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
	scanf("%d", &n);
	vector<int> ans;
	if(n < 10){
		printf("%d\n", n>0?n:10);
		return 0;
	}
	for(i=9;n>1&&i>1;--i){
		while(n%i==0){
			n/=i;
			ans.pb(i);
		}
	}
	if(n>1){
		puts("-1");
		return 0;
	}
	reverse(ans.begin(), ans.end());
	for(int x:ans)
		printf("%d", x);
	puts("");
	return 0;
}