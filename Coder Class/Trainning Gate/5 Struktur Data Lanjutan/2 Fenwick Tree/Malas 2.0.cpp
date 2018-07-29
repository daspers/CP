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
	FenwickTree(T* arr, int n){
		tree = new T[n+2];
		tree[0] = 0;
		sz = n;
		for(int i=1;i<=n;i++)
			tree[i] = tree[i-1]+arr[i];
		for(int i=n;i>1;i--)
			tree[i] -= tree[i - lastbit(i)];
	}
	~FenwickTree(){
		delete[] tree;
	}
	void update(int idx, T delta){
		for(;idx<=sz;idx += lastbit(idx))
			tree[idx] += delta;
	}
	T sum(int idx){
		T res = 0;
		while(idx >0){
			res += tree[idx];
			idx -= lastbit(idx);
		}
		return res;
	}
	static inline int lastbit(int a){
		return a&(-a);
	}
};

int n,i,j,k,t;
int m;
ll a[100002];

int main(){
	scanf("%d %d", &n, &m);
	for(i=1;i<=n;++i)
		scanf("%lld", a+i);
	FenwickTree<ll> ft(a, n);
	for(i=0;i<m;++i){
		int c,l,r;
		scanf("%d %d %d", &c, &l, &r);
		if(c==1){
			int tmp = a[l];
			a[l] ^= r;
			ft.update(l, a[l]-tmp);
		}
		else
			printf("%lld\n", ft.sum(r) - ft.sum(l-1));
	}
	return 0;
}