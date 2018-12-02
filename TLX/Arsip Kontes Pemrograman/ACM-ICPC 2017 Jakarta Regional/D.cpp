#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-8
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9+7;
const double pi = acos(-1);

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
		for(T x : arr)
			m.pb(x);
		sort(m.begin(), m.end());
		m.erase(unique(m.begin(), m.end()), m.end());
	}
	int get(T val){ return lower_bound(m.begin(), m.end(), val) - m.begin();}
	int operator[] (T val){ return get(val);}
};

int n,i,j,k,t;
int m;
pair<int, pii> a[100002];
multiset<pii> wew[200002];
vector<int> lst;
mapper<int> mep;

int main(){
	scanf("%d %d", &n, &m);
	for(i=0;i<n;++i){
		scanf("%d %d %d", &a[i].se.fi, &a[i].se.se, &a[i].fi);
		lst.pb(a[i].se.fi);
		lst.pb(a[i].se.se);
	}
	mep.mapping(lst);
	for(i=0;i<n;++i){
		a[i].se.fi = mep[a[i].se.fi];
		a[i].se.se = mep[a[i].se.se];
	}
	sort(a, a+n);
	int ans = 0;
	for(i=0;i<n;++i){
		multiset<pii>::iterator it = wew[a[i].se.fi].lower_bound({a[i].fi, 0});
		if(it == wew[a[i].se.fi].begin()){
			++ans;
			if(m > 1)
			wew[a[i].se.fi].insert({0, 1});
		}
		else{
			--it;
			pii tmp = *it;
			wew[a[i].se.fi].erase(it);
			++tmp.se;
			if(tmp.se < m)
				wew[a[i].se.fi].insert(tmp);
		}
		wew[a[i].se.se].insert({a[i].fi, 0});
	}
	printf("%d\n", ans);
	return 0;
}