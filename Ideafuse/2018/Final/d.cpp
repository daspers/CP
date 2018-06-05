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

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;  
    }
};

int n,i,j,k,t;
int x[2001], y[2001];

pair<int, int> makeit(int x, int y){
	int tmp = __gcd(abs(x), abs(y));
	if(tmp){
		x /= tmp;
		y /= tmp;
	}
	if(y<0){
		y = -y;
		x = -x;
	}
	else if(y==0)
		x = abs(x);
	return {x, y};
}

int main(){
	// scanf("%d", &t);
	// for(int cc=1;cc<=t;++cc){
		// printf("Case #%d: ", cc);
		scanf("%d", &n);
		for(i=0;i<n;++i)
			scanf("%d", x+i);
		for(i=0;i<n;++i)
			scanf("%d", y+i);
		int ans = 0;
		unordered_map<pair<int, int>, int, pair_hash> hasil;
		for(i=0;i<n-1;++i){
			unordered_map<pair<int, int>, int, pair_hash> mep;
			for(j=i+1;j<n;++j){
				mep[makeit(x[i]-x[j], y[i]-y[j])]++;
			}
			for(const auto & x: mep){
				if(x.se==1)
					hasil[x.fi]++;
			}
		}
		for(const auto & x: hasil){
			ans = max(ans, x.se);
			// cout<<x.fi.x<<	" "<<x.fi.y<<" "<<x.se<<endl;
		}
		printf("%d\n", (ans>1? ans : 0));
	// }
	return 0;
}
