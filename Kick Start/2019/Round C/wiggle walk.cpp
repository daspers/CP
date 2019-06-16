#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-9
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void printArray(const int *arr, int n);
void printArray(const vector<int> &arr);

const ll mod = 1e9+7;
const double PI = acos(-1);

int n,i,j,k,t;
int r,c,a,b;
char s[50005];
map<pii, int> up, dw, le, ri;

int main(){
	scanf("%d", &t);
	for(int cc=1;cc<=t;++cc){
		printf("Case #%d: ", cc);
		scanf("%d %d %d %d %d", &n, &r, &c, &a, &b);
		scanf("%s", s);
		up[{a,b}] = dw[{a,b}] = ri[{a,b}] = le[{a,b}] = 1;
		for(int i=0;i<n;++i){
			// cerr<<a<<" "<<b<<" "<<s[i]<<" become ";
			if(s[i] == 'N'){
				pii nxt = {a-1, b};
				while(up.count(nxt)){
					nxt.fi -= up[nxt];
				}
				up[nxt] = le[nxt] = ri[nxt] = 1;
				dw[nxt] = up[{a,b}] = abs(nxt.fi - a) + 1;
				a = nxt.fi;
				b = nxt.se;
			}
			else if(s[i] == 'S'){
				pii nxt = {a+1, b};
				while(dw.count(nxt)){
					nxt.fi += dw[nxt];
				}
				dw[nxt] = le[nxt] = ri[nxt] = 1;
				up[nxt] = dw[{a,b}] = abs(nxt.fi - a) + 1;
				a = nxt.fi;
				b = nxt.se;
			}
			else if(s[i] == 'E'){
				pii nxt = {a, b+1};
				while(ri.count(nxt)){
					nxt.se += ri[nxt];
				}
				dw[nxt] = up[nxt] = ri[nxt] = 1;
				le[nxt] = ri[{a,b}] = abs(nxt.se - b) + 1;
				a = nxt.fi;
				b = nxt.se;
			}
			else{
				pii nxt = {a, b-1};
				while(le.count(nxt)){
					nxt.se -= le[nxt];
				}
				dw[nxt] = up[nxt] = le[nxt] = 1;
				ri[nxt] = le[{a,b}] = abs(nxt.se - b) + 1;
				a = nxt.fi;
				b = nxt.se;
			}
			// cerr<<a<<" "<<b<<endl;
		}
		printf("%d %d\n", a, b);
		dw.clear();
		up.clear();
		ri.clear();
		le.clear();
	}
	return 0;
}

/* Template Function */
void printArray(const int * a, int n){
	for(int i=0;i<n;++i){
		printf("%d ", a[i]);
	}
	puts("");
}

void printArray(const vector<int> &arr){
	for(int x : arr){
		printf("%d ", x);
	}
	puts("");
}