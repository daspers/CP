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

struct vektor{
	ll a, b, c;
	vektor(ll x, ll y, ll z){
		a = x;
		b = y;
		c = z;
		simplify();
	}
	void simplify(){
		ll gcd = __gcd(llabs(a), __gcd(llabs(b), llabs(c)));
		if(gcd == 0)
			return;
		a /= gcd;
		b /= gcd;
		c /= gcd;
		if(c < 0){
			c = -c;
			b = -b;
			a = -a;
		}
		else if(c==0){
			if(b < 0){
				b = -b;
				a = -a;
			}
			else if(b==0)
				a = llabs(a);
		}
		else if(a==0 && b==0){
			c = llabs(c);
		}
	}
	friend bool operator<(const vektor& a, const vektor& b){
		if(a.c == b.c){
			if(a.b == b.b){
				if(a.a == b.a)
					return false;
				return a.a < b.a;
			}
			return a.b < b.b;
		}
		return a.c < b.c;
		
	}
};

int n,t,i,j,k;
ll a,b,c,x,y,z;
set<vektor> s;

int main(){
	scanf("%d", &n);
	scanf("%lld %lld %lld", &a, &b, &c);
	for(i=1;i<n;i++){
		scanf("%lld %lld %lld", &x, &y, &z);
		s.insert(vektor(x-a,y-b,z-c)); 
	}
	printf("%d\n", (int)s.size());
	return 0;
}