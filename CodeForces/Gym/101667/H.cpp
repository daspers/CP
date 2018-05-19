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
string s, p;
char c[] = "SPRS";

int main(){
	scanf("%d %d", &n, &m);
	cin>>s>>p;
	vector<int> ans(m+n+2, 0);
	for(i=0;i<3;++i){
		vector<int> x(n+1, 0), y(m+1, 0);
		for(j=0;j<n;++j){
			if(s[j]==c[i+1])
				x[j+1] = 1;
		}
		for(j=0;j<m;++j){
			if(p[j]==c[i])
				y[m-j-1] = 1;
		}
		vector<int> res = multiply(x, y);
		for(j=0;j<n+m;++j){
			ans[j] += res[j];
		}
	}
	int ma = 0;
	for(i=m;i<n+m;i++){
		ma = max(ma, ans[i]);
	}
	printf("%d\n", ma);
	return 0;
}