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
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		k = n/2+1;
		for(i=1;i<=n;i++){
			if(i==k)
				puts("Just Melati.");
			else
				puts("Selamat Bertanding!");
		}
	}
	return 0;
}
