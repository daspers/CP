#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define Nmax 300000 

typedef long long ll;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t,m;

int solve(int x){
	if(x<2)
		return 1;
	if(x&1)
		return solve(x/2);
	return solve(x/2) + solve((x-2)/2);
}

int main(){
	scanf("%d", &n);
	printf("%d\n", solve(n));
	return 0;
}