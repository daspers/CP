#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-9
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define debug2(a, b) cerr<<#a<<"="<<(a)<<" ";debug(b)
#define debug3(a, b, c) cerr<<#a<<"="<<(a)<<" ";debug2(b, c)
#define debug4(a, b, c, d) cerr<<#a<<"="<<(a)<<" ";debug3(b, c, d)
#define debug5(a, b, c, d, e) cerr<<#a<<"="<<(a)<<" ";debug4(b, c, d, e)
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<class T>
void printArray(const T * a, int n, ostream& out = cerr);
template<class T>
void printArray(const vector<T> &arr, ostream& out = cerr);

const ll mod = 1e9+7;
const double PI = acos(-1);

int n,i,j,k,t;
int m;
map<string, int> mep;
int a[1002];
vector<int> f[102], e[1002];
vector<string> dmp[1002];

int main(){
    cin>>n>>m;
    int curr = 0;
    vector<int> x;
    for(int i=0;i<m;++i){
        cin>>a[i];
        for(int j=0;j<a[i];++j){
            string s;
            cin>>s;
            dmp[i].pb(s);
            if(!mep.count(s)){
                mep[s] = curr++;
            }
        }
        for(int j=0;j<a[i];++j){
            int wew;
            cin>>wew;
            x.pb(wew);
        }
    }
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    bool space = false;
    for(const pair<string, int> &x : mep){
        if(space) cout<<(" ");
        else space = true;
        cout<<x.fi;
    }
    cout<<endl;
    for(int i=0;i<n;++i){
        if(i>0) cout<<(" ");
        cout<<x[i];
    }
    cout<<endl;
    return 0;
}

/* Template Function */
template<class T>
void printArray(const T * a, int n, ostream& out){
    for(int i=0;i<n;++i){
        out<<a[i]<<" ";
    }
    out<<endl;
}

template<class T>
void printArray(const vector<T> &arr, ostream& out){
    for(const T& x : arr){
        out<<x<<" ";
    }
    out<<endl;
}