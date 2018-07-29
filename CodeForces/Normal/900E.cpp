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
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
int m;
int c[100002], psum[100002];
pii dp[100002];
string s;

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

int main(){
	scanf("%d", &n);
	cin>>s;
	scanf("%d", &m);
	vector<int> a(n+1, 0), b(m, 0), tmp;
	/* get a */
	for(i=0;i<n;++i)
		if(s[i]!='b')
			a[i+1]=1;
	for(i=0;i<m;++i)
		if(!(i&1))
			b[m-i-1] = 1;
	tmp =  multiply(a, b);
	for(i=0;i<n;++i)
		c[i]+= tmp[i+m];
	/* get b */
	a.assign(n+1, 0);
	for(i=0;i<n;++i)
		if(s[i]!='a')
			a[i+1]=1;
	for(i=0;i<m;++i)
		b[i] = !b[i];
	tmp =  multiply(a, b);
	for(i=0;i<n;++i)
		c[i]+= tmp[i+m];
	// for(i=0;i<n;++i)
		// cout<<c[i]<<" ";
	// cout<<endl;
	/* Algorithm */
	if(*max_element(c, c+n)!=m){
		puts("0");
		return 0;
	}
	psum[n]=0;
	for(i=n-1;i>=0;--i)
		psum[i] = psum[i+1] + (s[i] == '?');
	memset(dp, 0, sizeof dp);
	for(i=n-m;i>=0;--i){
		dp[i] = dp[i+1];
		if(c[i]==m)
			dp[i] = max(dp[i], {dp[i+m].fi+1, dp[i+m].se+psum[i+m]-psum[i]});
	}
	printf("%d\n", -dp[0].se);
	return 0;
}