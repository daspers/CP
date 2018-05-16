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
 
int n,i,j,k,t,m;
string s;

int main(){
	cin>>s;
	int x=0,y=0;
	for(char c: s){
		if(c=='S')
			y--;
		else if(c=='N')
			y++;
		else if(c=='W')
			x++;
		else if(c=='E')
			x--;
	}
	printf("%d\n", abs(x)+abs(y));
	return 0;
}