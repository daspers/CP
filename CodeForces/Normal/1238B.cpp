#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-9
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define debug2(a, b) cerr<<#a<<"="<<(a)<<" ";debug(b)
#define debug3(a, b, c) cerr<<#a<<"="<<(a)<<" ";debug2(b, c)
#define debug4(a, b, c, d) cerr<<#a<<"="<<(a)<<" ";debug3(b, c, d)
#define debug5(a, b, c, d, e) cerr<<#a<<"="<<(a)<<" ";debug4(b, c, d, e)
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<class T>
void printArray(const T * a, int n, ostream& out = cerr);
template<class T>
void printArray(const vector<T> &arr, ostream& out = cerr);

const ll mod = 1e9+7;
const double PI = acos(-1);

int n,i,j,k,t;
int a[100002];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &k);
		for(int i=0;i<n;++i){
			scanf("%d", a+i);
		}
		int ans = 0;
		int off = 0;
		set<int> s;
		sort(a, a+n, greater<int>());
		for(int i=0;i<n;++i){
			if(s.count(a[i])) continue;
			if(a[i] <= off) break;
			ans ++;
			off += k;
			s.insert(a[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}

/* Template Function */
template<class T>
void printArray(const T * a, int n, ostream& out){
	for(int i=0;i<n;++i){
		out<<a[i]<<" ";
	}
	out<<endl;
}

template<class T>
void printArray(const vector<T> &arr, ostream& out){
	for(const T& x : arr){
		out<<x<<" ";
	}
	out<<endl;
}