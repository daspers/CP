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

const ll mod = 998244353;
const double PI = acos(-1);

int n,i,j,k,t;
int a[200003], b[200003];
pii c[200003];
bool used[200003];
int m, sum;

bool coba(int tg){
	std::vector<pii> v;
	memset(used, 0, sizeof used);
	for(int i=m-1;i>=0;--i){
		if(c[i].fi > tg) continue;
		if(used[c[i].se]) continue;
		used[c[i].se] = true;
		v.pb(c[i]);
	}
	reverse(v.begin(), v.end());
	int curr = 0;
	int coin = 0;
	int rem = sum;
	for(const pii &x : v){
		coin += x.fi - curr;
		curr = x.fi;
		int mi = min(coin, a[x.se]);
		coin -= mi;
		rem -= mi;
	}
	coin += tg - curr;
	return coin >= rem*2;
}

int main(){
	scanf("%d %d", &n, &m);
	sum = 0;
	for(int i=0;i<n;++i){
		scanf("%d", a+i);
		sum += a[i];
	}
	for(int i=0;i<m;++i){
		scanf("%d %d", &c[i].fi, &c[i].se);
		c[i].se--;
	}
	sort(c, c+m);
	int l = 1, r=2*sum#include <bits/stdc++.h>

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

const ll mod = 998244353;
const double PI = acos(-1);

int n,i,j,k,t;
int a[200003], b[200003];
pii c[200003];
bool used[200003];
int m, sum;

bool coba(int tg){
	std::vector<pii> v;
	memset(used, 0, sizeof used);
	for(int i=m-1;i>=0;--i){
		if(c[i].fi > tg) continue;
		if(used[c[i].se]) continue;
		used[c[i].se] = true;
		v.pb(c[i]);
	}
	reverse(v.begin(), v.end());
	int curr = 0;
	int coin = 0;
	int rem = sum;
	for(const pii &x : v){
		coin += x.fi - curr;
		curr = x.fi;
		int mi = min(coin, a[x.se]);
		coin -= mi;
		rem -= mi;
	}
	coin += tg - curr;
	return coin >= rem*2;
}

int main(){
	scanf("%d %d", &n, &m);
	sum = 0;
	for(int i=0;i<n;++i){
		scanf("%d", a+i);
		sum += a[i];
	}
	for(int i=0;i<m;++i){
		scanf("%d %d", &c[i].fi, &c[i].se);
		c[i].se--;
	}
	sort(c, c+m);
	int l = 1, r=2*sum;
	while(l < r){
		int mid = (l+r)/2;
		if(coba(mid)){
			r = mid;
		}
		else{
			l = mid+1;
		}
	}
	printf("%d\n", r);
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
/*
two plus xor of third and min element
ltabraccanepgcefbopnosisoc
*/
	while(l < r){
		int mid = (l+r)/2;
		if(coba(mid)){
			r = mid;
		}
		else{
			l = mid+1;
		}
	}
	printf("%d\n", r);
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