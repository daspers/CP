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
		res.pb(floor(fa[i].real()+0.5));
	}
	return res;
}

int n,i,j,k,t,m;
char s[500002], p[500002];
char x;

int main(){
	for(n=0;x = getchar(), !isspace(x);++n){
		s[n]=x;
	}
	for(m=0;x = getchar(), !isspace(x);++m){
		p[m]=x;
	}
	vector<int> ans(n+m+1, 0);
	for(char c : "ACTG"){
		vector<int> a(n+1,  0), b(m, 0);
		for(int i=0;i<n;++i){
			if(s[i]==c)
				a[i+1] = 1;
		}
		for(int i=0;i<m;++i){
			if(p[i]==c)
				b[m-i-1] = 1;
		}
		vector<int> res = multiply(a, b);
		for(int i=0;i<=n+m;++i){
			ans[i] += res[i];
		}
	}
	// i=0;
	// cout<<n<<" "<<m<<endl;
	// for(int x : ans){
		// cout<<i<<" "<<x<<endl;
		// ++i;
	// }
	printf("%d\n", m-*max_element(ans.begin()+m, ans.begin()+n+1));
	return 0;
}
