#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define Nmax 300000

typedef long long ll;
typedef complex<double> cd;

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
		double ang = 2.0*pi/len*neg;
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

vector<ll> multiply(const vector<int> &a, const vector<int> &b){
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
		res.pb(round(fa[i].real()));
	}
	return res;
}

int n,i,j,k,t,m;
ll a[200002], p[200002];

int main(){
	scanf("%d", &n);
	for(i=1;i<=n;++i){
		scanf("%lld", a+i);
	}
	int ans = 0;
	if(n<=3000){
		set<ll> ada;
		for(i=1;i<=n;++i){
			ll sum = 0;
			for(j=i;j<=n;++j){
				sum += a[j];
				ada.insert(sum);
			}
		}
		ans = ada.size()-1;
	}
	else if(n<=20000){
		bitset<2000001> ada;
		for(i=1;i<=n;++i){
			ll sum = 0;
			for(j=i;j<=n;++j){
				sum += a[j];
				ada[sum] = 1;
			}
		}
		for(i=0;i<=2000000;++i)
			ans += ada[i];
		ans--;
	}
	else{
		p[0] = 0;
		for(i=1;i<=n;++i)
			p[i] = a[i] + p[i-1];
		vector<int> f(p[n]+1,0), g(p[n]+1,0);
		for(i=0;i<=n;++i){
			f[p[i]]=1;
			g[p[n]-p[i]]=1;
		}
		vector<ll> res = multiply(f, g);
		for(i=p[n]+1;i<res.size();++i)
			ans += res[i]!=0;
		ans--;
	}
	printf("%d\n", ans);
	return 0;
}