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
int a,b,c,f;
pair<int, int> d[200003];
map<pair<int, int>, int> m;

int main(){
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("\n(%d+%d)/%d", &a, &b, &c);
		f = __gcd(a+b, c);
		d[i] = {(a+b)/f, c/f};
		m[d[i]]++;
	}
	for(i=0;i<n;i++){
		printf("%d ", m[d[i]]);
	}
	puts("");
	return 0;
}