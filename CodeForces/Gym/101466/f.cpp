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

struct triangle{
	int a,b,c;
	void read(){
		scanf("%d %d %d", &a, &b, &c);
	}
	bool valid(){
		return a+b>c && a+c>b && b+c>a;
	}
	int maks(){
		return max(a, max(b, c));
	}
};

int n,t,i,j,k,m;
triangle a[1000003];

int main(){
	scanf("%d", &n);
	for(i=0;i<n;i++)
		a[i].read();
	for(i=0;i<n;i++){
		if(!a[i].valid())
			return puts("NO");
	}
	puts("YES");
	return 0;
}