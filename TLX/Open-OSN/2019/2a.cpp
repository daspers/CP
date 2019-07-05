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

template<class T>
struct mapper{
	std::vector<T> m;
	mapper(){}
	mapper(const T *arr, int sz){mapping(arr, sz);}
	mapper(const vector<T> &arr){mapping(arr);}
	void mapping(const T *arr, int sz){
		m.clear();
		for(int i=0;i<sz;++i)
			m.pb(arr[i]);
		sort(m.begin(), m.end());
		m.erase(unique(m.begin(), m.end()), m.end());
	}
	void mapping(const vector<T> &arr){
		m.clear();
		for(const T &x : arr)
			m.pb(x);
		sort(m.begin(), m.end());
		m.erase(unique(m.begin(), m.end()), m.end());
	}
	int get(const T &val){ return lower_bound(m.begin(), m.end(), val) - m.begin();}
	int operator[] (const T &val){ return get(val) + 1;}
};

int n,i,j,k,t;
int m;
pii p[200002];
int cntr[400004];
int cntl[400004];
mapper<int> mep;

int main(){
	scanf("%d %d", &n, &m);
    vector<int> v;
    for(int i=0;i<n;++i){
        scanf("%d %d", &p[i].fi, &p[i].se);
        v.pb(p[i].fi);
        v.pb(p[i].se);
    }
    mep.mapping(v);
    memset(cntl, 0, sizeof cntl);
    memset(cntr, 0, sizeof cntr);
    for(int i=0;i<n;++i){
        cntl[mep[p[i].se]] ++;
        cntr[mep[p[i].fi]] ++;
    }
    for(int i=1;i<=mep.m.size();++i){
        cntl[i] += cntl[i-1];
    }
    for(int i=mep.m.size()+1;i>=0;--i){
        cntr[i] += cntr[i+1];
    }
    for(int i=0;i<n;++i){
        printf("%d\n", n - (cntl[mep[p[i].fi]-1] + cntr[mep[p[i].se]+1])-1);
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