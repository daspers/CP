#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;

const ll mod = 1111111111;
const double pi = acos(-1);

int n,t,j,i,k,m;
ll arr[1000002];

int main(){
	arr[0] = 1;
	for(int i=1;i<=500000;i++){
		arr[i] += arr[i-1] + i+1;
	}
	while(scanf("%d", &n)>0){
		printf("%lld\n", arr[n/2]);
	}
	return 0;
}