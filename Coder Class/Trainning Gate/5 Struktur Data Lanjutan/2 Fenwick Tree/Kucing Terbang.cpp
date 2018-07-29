#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-9
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"

typedef long long ll;
typedef complex<double> cd;
typedef pair<int, int> pii;

const ll mod = 1e9+7;
const double pi = acos(-1);

template<class T>
struct FenwickTree{
	T *tree;
	int sz;
	FenwickTree(int n){
		tree = new T[n+2];
		memset(tree, 0, (n+2)*sizeof *tree);
		sz = n;
	}
	~FenwickTree(){
		delete[] tree;
	}
	void update(int idx, T delta){
		for(;idx<=sz;idx += lastbit(idx)){
			tree[idx] += delta;
			tree[idx] %= mod;
		}
	}
	T sum(int idx){
		T res = 0;
		while(idx >0){
			res += tree[idx];
			res %= mod;
			idx -= lastbit(idx);
		}
		return res;
	}
	static inline int lastbit(int a){
		return a&(-a);
	}
};

int n,i,j,k,t;

int main(){
	FenwickTree<ll> ft(100000);
	scanf("%d", &n);
	for(i=0;i<n;++i){
		scanf("%d", &t);
		ll tmp = ft.sum(t)+1;
		ft.update(t,tmp);
	}
	printf("%lld\n", ft.sum(100000));
	return 0;
}