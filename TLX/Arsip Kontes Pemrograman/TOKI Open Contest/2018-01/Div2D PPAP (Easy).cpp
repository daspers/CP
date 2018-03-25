
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;

const ll mod = 1e9+7;

ll n, i, j, k, t, pre;
ll p[100002];
string s;

int main(){
	scanf("%lld", &n);
	cin>>s;
	p[0]=0;
	pre=0;
	t=0;
	for(i=1;i<=n;i++){
		p[i]=p[i-1];
		if(s[i-1]=='P'){
			t+=pre;
			t%=mod;
		}
		if(s[i-1]=='P')
			p[i]++;
		else if(p[i]>1){
			pre +=(p[i]*(p[i]-1)/2)%mod;
			pre %=mod;
		}
	}
	printf("%lld\n", t);
	return 0;
}
