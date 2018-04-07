#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef unsigned long long ull;
 
const ll mod = 1e9+7;
const double pi = acos(-1);

struct lib
{
	int l;
	int r;
	int i;
};

int n,t,j,i,k;
string a, b;
deque<char> c, d;


int main(){
	cin>>a>>b;
	for(char & x: a){
		c.push_back(x);
	}
	for(char & x: b){
		d.push_back(x);
	}
	while(!c.empty() && c.front()==d.front()){
		c.pop_front();
		d.pop_back();
	}
	while(!d.empty() && c.back()==d.back()){
		c.pop_back();
		d.pop_back();	
	}
	if(a.size()){
		reverse(a.begin(), a.end());
		if(a!=b){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}