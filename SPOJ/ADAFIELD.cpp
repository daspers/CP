#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-8
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
int q, m;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &n, &m, &q);
		multiset<int> w, l;
		map<int, int> wr, lr;
		map<int, int>::iterator it;
		wr[0] = n;
		lr[0] = m;
		w.insert(n);
		l.insert(m);
		while(q--){
			int a, b;
			scanf("%d %d", &a, &b);
			if(a){
				it = --lr.upper_bound(b);
				if(it->fi != it->se){
					int tmp = it->se;
					l.erase(l.lower_bound(it->se-it->fi));
					it->se = b;
					if(it->fi != it->se)
						l.insert(it->se - it->fi);
					if(b != tmp)
						l.insert(tmp-b);
					lr[b] = tmp;
				}
			}
			else{
				it = --wr.upper_bound(b);
				if(it->fi != it->se){
					int tmp = it->se;
					w.erase(w.lower_bound(it->se-it->fi));
					it->se = b;
					if(it->fi != it->se)
						w.insert(it->se - it->fi);
					if(b != tmp)
						w.insert(tmp-b);
					wr[b] = tmp;
				}
			}
			printf("%lld\n", 1LL*(*w.crbegin())*(*l.crbegin()));
		}
	}
	return 0;
}