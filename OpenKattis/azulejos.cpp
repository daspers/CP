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
	int operator[] (const T &val){ return get(val);}
};

int n,i,j,k,t;
multiset<pii> a[1000002];
multiset<pii> b[1000002];
pair<int, int> c[500005], d[500005];
std::vector<int> v;
std::vector<int> ans1, ans2;
mapper<int> mep;

int main(){
	scanf("%d", &n);
	for(int i=0;i<n;++i){
		scanf("%d", &d[i].fi);
		v.pb(d[i].fi);
	}
	for(int i=0;i<n;++i){
		scanf("%d", &d[i].se);
	}
	for(int i=0;i<n;++i){
		scanf("%d", &c[i].fi);
		v.pb(c[i].fi);
	}
	for(int i=0;i<n;++i){
		scanf("%d", &c[i].se);
	}
	mep.mapping(v);
	for(int i=0;i<n;++i){
		a[mep[c[i].fi]].insert({c[i].se, i});
		b[mep[d[i].fi]].insert({d[i].se, i});
	}
	multiset<pii>::iterator it;
	for(int i=0,j=0;i<mep.m.size() && j<mep.m.size();){
		if(a[i].size() == 0){
			++i;
		}
		else if(b[j].size() == 0){
			++j;
		}
		else{
			if(a[i].size() <= b[j].size()){
				while(!a[i].empty()){
					pii top = *a[i].begin();
					a[i].erase(a[i].begin());
					it = b[j].upper_bound({top.fi, n});
					if(it == b[j].end()){
						return puts("impossible"), 0;
					}
					ans1.pb(top.se);
					ans2.pb(it->se);
					b[j].erase(it);
				}
				++i;
			}
			else{
				while(!b[j].empty()){
					pii top = *b[j].begin();
					b[j].erase(b[j].begin());
					it = a[i].lower_bound({top.fi, 0});
					if(it == a[i].begin()){
						return puts("impossible"), 0;
					}
					--it;
					ans1.pb(it->se);
					ans2.pb(top.se);
					a[i].erase(it);
				}
				++j;
			}
		}
	}
	for(int x : ans2){
		printf("%d ", x + 1);
	}
	puts("");
	for(int x : ans1){
		printf("%d ", x + 1);
	}
	puts("");
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