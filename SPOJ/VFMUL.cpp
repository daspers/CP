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
		res.pb(round(fa[i].real()));	//easy
	}
	return res;
}

int n,i,j,k,t,m;

int main(){
	scanf("%d", &t); getchar();
	while(t--){
		char c;
		vector<int> a, b;
		while(c=getchar(), !isspace(c))
			a.pb(c-'0');
		reverse(a.begin(), a.end());
		while(c=getchar(), !isspace(c))
			b.pb(c-'0');
		reverse(b.begin(), b.end());
		vector<int> ans = multiply(a, b);
		n = ans.size();
		while(n>0&&ans[n-1] == 0)
			n--;
		if(n==0)
			puts("0");
		else{
			for(i=0;i<n-1;++i){
				if(ans[i]>9){
					ans[i+1] += ans[i]/10;
					ans[i]%=10;
				}
			}
			for(i=n-1;i>=0;--i)
				printf("%d", ans[i]);
			puts("");
		}
	}
	return 0;
}