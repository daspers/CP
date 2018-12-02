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
int arr[1002][1002];

int main(){
	scanf("%d %d", &n, &k);
	memset(arr, 0, sizeof arr);
	int tmp = 1;
	vector<int> wew;	
	for(i=0;i<n*n-n;++i){
		wew.pb(tmp++);
	}
	for(i=0;i<n;++i)
		arr[i][i] = tmp++;
	while(k){
		int c = 0;
		for(i=0;i<n;++i){
			for(j=0;j<n;++j){
				if(i != j)
					arr[i][j] = wew[c++];
			}
		}
		for(i=0;i<n;++i){
			for(j=0;j<n;++j){
				if(j) printf(" ");
				printf("%d", arr[i][j]);
			}
			puts("");
		}
		next_permutation(wew.begin(), wew.end());
		k--;
	}
	return 0;
}