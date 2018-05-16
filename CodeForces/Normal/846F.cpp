#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,t,i,j,k;
set<int> s;
int arr[1000002], pre[1000002];
map<int, int> mip;

int main(){
	memset(pre, -1, sizeof pre);
	ll n;
	scanf("%lld", &n);
	ll sum = (n*n*n + 3*n*n-n)/3;
	for(int i=0;i<n;i++){
		scanf("%d", arr+i);
	}
	for(int i=0;i<n;i++){
		if(pre[arr[i]] != -1){
			sum -= (ll) 2*pre[arr[i]]*(n-i);
		}
		pre[arr[i]] = i+1;
	}
	printf("%.7lf\n", (double) 1.0*(sum)/(n*n));
}