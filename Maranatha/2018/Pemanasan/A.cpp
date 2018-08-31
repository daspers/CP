#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-8
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
int a[102], b[102];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(i=0;i<n;++i){
			scanf("%d", a+i);
			b[i] = a[i];
		}
		sort(b, b+n);
		int len = n;
		while(len > 0){
			if(a[len-1] == b[len-1])
				len--;
			else if(a[0] == b[len-1]){
				reverse(a, a+len);
				printf("%d ", n-len+1);
			}
			else{
				for(i=0;i<len;++i)
					if(a[i] == b[len-1])
						break;
				reverse(a, a+i+1);
				printf("%d ", n-i);
			}
		}
		puts("0");
	}
	return 0;
}