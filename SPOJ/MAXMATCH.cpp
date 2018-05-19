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

vector<int> multiply(const vector<int> &a, const vector<int> &b){
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
	
	vector<int> res;
	for(int i=0;i<sz;++i){
		res.pb(round(fa[i].real()));
	}
	return res;
}

int n,i,j,k,t,m;
string s;
char c;

int main(){
	cin>>s;
	n = s.size();
	vector<int> ans(2*n+1, 0);
	for(c='a';c<='c';++c){
		vector<int> x(n+1, 0), y(n+1, 0);
		for(i=0;i<n;++i){
			if(s[i]==c){
				x[i+1] = 1;
				y[s.size()-i-1] = 1;
			}
		}
		vector<int> res = multiply(x, y);
		for(i=0;i<=2*n;++i){
			ans[i] += res[i];
		}
	}
	int ma = 0;
	for(i=n+1;i<2*n;i++){
		ma = max(ma, ans[i]);
	}
	printf("%d\n", ma);
	for(i=n+1;i<2*n;i++){
		if(ans[i]==ma)
			printf("%d ", i-n);
	}
	puts("");
	return 0;
}