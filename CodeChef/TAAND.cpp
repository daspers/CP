#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define INF 200000001
#define EPS 1e-9

typedef long long ll;
typedef complex<double> cd;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
int a[100002];
int bit[32];
int tmp;

int main(){
	memset(bit, 0, sizeof bit);
	scanf("%d", &n);
	vector<int> a;
	for(i=0;i<n;++i){
		scanf("%d", &t);
		a.pb(t);
	}
	int answer = 0;
	while(a.size()>1){
		memset(bit, 0, sizeof bit);
		for(int x : a){
			for(int i=0;x;++i){
				if(x&1)
					bit[i]++;
				x >>= 1;
			}
		}
		for(i=31;i>=0;--i){
			if(bit[i]>1)
				break;
		}
		if(i<0)
			break;
		tmp = 1<<i;
		sort(a.begin(), a.end(), [](const int &a, const int &b){
			int c = a & tmp;
			int d = b & tmp;
			if(c==d)
				return a < b;
			else
				return c > d;
		});
		a.erase(a.begin()+bit[i], a.end());
		answer += tmp--;
		for(int &x : a){
			x &=tmp;
		}
	}
	printf("%d\n", answer);
	return 0;
}
