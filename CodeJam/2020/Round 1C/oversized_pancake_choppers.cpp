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
int m;
ll a[10002];
int cnt[10002];

int main(){
    scanf("%d", &t);
    for(int cc=1;cc<=t;++cc){
        printf("Case #%d: ", cc);
        scanf("%d %d", &n, &m);
        for(int i=0;i<n;++i){
            scanf("%d", a+i);
        }
        mapper<ll> mep(a, n);
        int sz = mep.m.size();
        for(int i=0;i<n;++i){
            cnt[mep[a[i]]]++;
        }
        int ans = m-1;
        for(int i=sz-1;i>=0;--i){
            if(cnt[i] >= m) ans = 0;
            if(m % mep.m[i] == 0){
                ans = min((ll)ans, (m / mep.m[i]) * (mep.m[i] - 1));
            }
            int cnt = 0;
            for(int j=i+1;j<sz;++j) cnt += mep.m[j] / mep.m[j];
        }
    }
    return 0;
}
// 1 2 3

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