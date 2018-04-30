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
int p;
int a[20002], ps[20002];
int dp[20001][51][2];

int hitung(int idx, int bagi, int ambil){
	if(dp[idx][bagi][ambil] == -1){
		if(n-idx < bagi)
			dp[idx][bagi][ambil] = 0;
		else if(ambil){
			dp[idx][bagi][ambil] = (a[idx]+hitung(idx+1, bagi, 0))%p;
		}
		else{
			dp[idx][bagi][ambil] = max((a[idx]+hitung(idx+1, bagi, 0))%p, hitung(idx, bagi-1,1));
		}
	}
	return dp[idx][bagi][ambil];
}


int main(){
	memset(dp, -1, sizeof dp);
	scanf("%d %d %d", &n, &k, &p);
	ps[0] = 0;
	for(i=1;i<=n;i++){
		scanf("%d", a+i);
		a[i] %= p;
		ps[i] = ps[i-1] + a[i];
	}
	for(i=1;i<=n;i++){
		dp[i][1][0] = dp[i][1][1] = (ps[n] - ps[i-1])%p;
	}
	dp[0][k][0] = 0;
	dp[0][k][1] = 0;
	printf("%d\n", hitung(1, k, 1));
	return 0;
}