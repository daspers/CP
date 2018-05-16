#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>

typedef long long ll;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,t,i,j,k,m;
int a[50];

int main(){
	scanf("%d", &n);
	string ans="";
	while(n){
		if(n&1){
			ans += 'A';
			n-=1;
		}
		else{
			ans += 'B';
			n -=2;
		}
		n>>=1;
	}
	reverse(ans.begin(), ans.end());
	cout<<ans<<"\n";
}