#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-9
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void printArray(const int *arr, int n);
void printArray(const vector<int> &arr);

const ll mod = 1e9+7;
const double PI = acos(-1);

int n,i,j,k,t;
int m, q;
int d[5];

pii intersect(int a, int b){
    // x+y=a
    // x-y=b
    // cerr<<"> "<<a<<" "<<b<<endl;
    if((a + b)% 2) return {-1, -1};
    return {(a+b)/2, (a-b)/2};
}

map<pii, int> mep;
vector<pii> sep;

int main(){
	cin>>n>>m>>q;
    cout<<"? "<<1<<" "<<1<<endl;
    cin>>d[0];
    cout<<"? "<<1<<" "<<m<<endl;
    cin>>d[1];
    cout<<"? "<<n<<" "<<m<<endl;
    cin>>d[2];
    cout<<"? "<<n<<" "<<1<<endl;
    cin>>d[3];
    set<pii> wew;
    pii tmp;
    tmp = intersect(d[0]+2, d[1]+1-m);
    mep[tmp] = 0;
    sep.pb(tmp);
    if(tmp.fi > 0 && tmp.fi <= n && tmp.se >0 && tmp.se <=m) wew.insert(tmp);
    tmp = intersect(d[0]+2, n-1-d[3]);
    mep[tmp] = 1;
    sep.pb(tmp);
    if(tmp.fi > 0 && tmp.fi <= n && tmp.se >0 && tmp.se <=m) wew.insert(tmp);
    tmp = intersect(n+m-d[2], n-1-d[3]);
    mep[tmp] = 2;
    sep.pb(tmp);
    if(tmp.fi > 0 && tmp.fi <= n && tmp.se >0 && tmp.se <=m) wew.insert(tmp);
    tmp = intersect(n+m-d[2], d[1]+1-m);
    mep[tmp] = 3;
    sep.pb(tmp);
    if(tmp.fi > 0 && tmp.fi <= n && tmp.se >0 && tmp.se <=m) wew.insert(tmp);
    pii a, b;
    vector<pii> v(wew.begin(), wew.end());
    // debug(wew.size());
    if(wew.size() == 1){
        a = b = *wew.begin();
    }
    else if(wew.size() == 2){
        a = *wew.begin();
        b = *wew.rbegin();
    }
    else if(q == 100){
        wew.clear();
        for(int i=0;i<v.size();++i){
            cout<<"? "<<v[i].fi<<" "<<v[i].se<<endl;
            int x;
            cin>>x;
            if(!x) wew.insert(v[i]);
        }
        if(wew.size() == 1) {
            a = b = *wew.begin()    ;
        }
        else if(wew.size() == 2){
            a = *wew.begin();
            b = *wew.rbegin();
        }
    }
    else{
        cout<<"? "<<v[0].fi<<" "<<v[0].se<<endl;
        int x;
        cin>>x;
        int idx = mep[v[0]];
        if(x) {
            a = sep[(idx+1)%4];
            b = sep[(idx+3)%4];
        }
        else{
            a = sep[(idx)%4];
            b = sep[(idx+2)%4];
        }
    }
    cout<<"! "<<a.fi<<" "<<a.se<<" "<<b.fi<<" "<<b.se<<endl;
	return 0;
}

/* Template Function */
void printArray(const int * a, int n){
	for(int i=0;i<n;++i){
		printf("%d ", a[i]);
	}
	puts("");
}

void printArray(const vector<int> &arr){
	for(int x : arr){
		printf("%d ", x);
	}
	puts("");
}