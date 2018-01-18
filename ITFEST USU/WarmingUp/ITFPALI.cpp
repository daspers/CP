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
		cin>>s;
		for(i=0,j=s.size()-1;i<j;i++,j--)
			if(s[i]!=s[j]){
				puts("BUKAN PALINDROM");
				goto hell;
			}
		puts("PALINDROM");
		hell:;
	}
	return 0;
}
