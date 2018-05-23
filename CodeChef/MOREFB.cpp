#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define Nmax 300000 

typedef long long ll;
typedef complex<long double> cd;

const ll mod = 1e9+7;
const double pi = acos(-1);

void fft(vector<cd> &a, bool invert){
	int n = a.size();
	for(int i=1,j=0;i<n;++i){
		int bit = n >>1;
		for(;j&bit;bit>>=1)
			j ^= bit;
		j ^= bit;
		if(i<j)
			swap(a[i],a[j]);
	}
	int neg = invert?-1:1;
	for(int len=2;len<=n;len<<=1){
		long double ang = 2.0*pi/len*neg;
		cd wn(cos(ang), sin(ang));
		for(int i=0;i<n;i+=len){
			cd w(1);
			for(int j=0;j<len/2;++j){
				cd u=a[i+j], v=a[i+j+len/2]*w;
				a[i+j] = u+v;
				a[i+j+len/2] = u-v;
				w *= wn;
			}
		}
	}
	if(invert)
		for(cd & tmp : a)
			tmp/=n;
}

vector<ll> multiply(const vector<ll> &a, const vector<ll> &b){
	vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	int sz = 1;
	while(sz < a.size()+b.size())
		sz <<= 1;
	fa.resize(sz);
	fb.resize(sz);
	fft(fa, false);
	fft(fb, false);
	
	for(int i=0;i<sz;++i)
		fa[i] *= fb[i];
	fft(fa, true);
	
	vector<ll> res;
	for(int i=0;i<sz;++i){
		res.pb(ll(floorl(fa[i].real()+0.5L)) % 99991LL);
	}
	return res;
}

const int c = 10104;
int n,i,j,k,t,m;
int a[50002];
ll pa[30];
ll pb[30];

void preprocess();
ll pangkata(int x);
ll pangkatb(int x);

vector<ll> geta(int l, int r){
	if(l==r){
		return {pangkata(a[l]), 1};
	}
	int mid = (l+r)>>1;
	return multiply(geta(l, mid), geta(mid+1, r));
}

vector<ll> getb(int l, int r){
	if(l==r){
		return {pangkatb(a[l]), 1};
	}
	int mid = (l+r)>>1;
	return multiply(getb(l, mid), getb(mid+1, r));
}

int main(){
	preprocess();
	scanf("%d %d", &n, &k);
	for(i=0;i<n;++i){
		scanf("%d", a+i);
		a[i] %= 33330;
	}
	ll ans = ((geta(0, n-1)[n-k] - getb(0,n-1)[n-k])*22019) % 99991;
	if(ans < 0)
		ans += 99991;
	printf("%lld\n", ans);
	return 0;
}

void preprocess(){
	pa[0] = 55048;
	pb[0] = 44944;
	for(int i=1;i<30;++i){
		pa[i]=(pa[i-1]*pa[i-1])%99991;
		pb[i]=(pb[i-1]*pb[i-1])%99991;
	}
}

inline ll pangkata(int x){
	ll res = 1;
	for(int i=0;x;++i){
		if(x&1){
			res *= pa[i];
			res %= 99991;
		}
		x>>=1;
	}
	return res;
}

inline ll pangkatb(int x){
	ll res = 1;
	for(int i=0;x;++i){
		if(x&1){
			res *= pb[i];
			res %= 99991;
		}
		x>>=1;
	}
	return res;
}
