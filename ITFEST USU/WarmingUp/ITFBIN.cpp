#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;

int const mod = 1e9+7;

int n,i,j,k,t,x,y;
string s;

int main(){
	scanf("%d", &n);
	while(n--){
		cin>>s;
		bitset<8> b(s);
		int ans;
		if(b[7] ==1){
			b = ~b;
			ans = b.to_ulong();
			ans = ~ans;
		}
		else
			ans = b.to_ulong();
		cout<<ans<<"\n";
	}
	return 0;
}
