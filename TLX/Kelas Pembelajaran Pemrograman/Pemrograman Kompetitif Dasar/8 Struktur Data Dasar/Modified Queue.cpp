#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-9

typedef long long ll;
typedef complex<double> cd;
typedef pair<int, int> pii;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t,p;
deque<pii> dq;
string s;

int main(){
	cin>>n;
	ll sz = 0;
	int a,b;
	bool rev = false;
	for(i=0;i<n;++i){
		cin>>s;
		if(s=="add"){
			cin>>a>>b;
			sz += b;
			if(rev)
				dq.push_front({a,b});
			else
				dq.push_back({a,b});
			cout<<sz<<'\n';
		}
		else if(s=="del"){
			cin>>b;
			sz -= b;
			pii tmp;
			if(rev){
				cout<<dq.back().fi<<'\n';
				while(b>0){
					tmp = dq.back();
					dq.pop_back();
					int kur = min(tmp.se, b);
					b -= kur;
					tmp.se -= kur;
					if(tmp.se){
						dq.push_back(tmp);
					}
				}
			}
			else{
				cout<<dq.front().fi<<'\n';
				while(b>0){
					tmp = dq.front();
					dq.pop_front();
					int kur = min(tmp.se, b);
					b -= kur;
					tmp.se -= kur;
					if(tmp.se){
						dq.push_front(tmp);
					}
				}
			}
		}
		else{
			rev = !rev;
		}
	}

	return 0;
}