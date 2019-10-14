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
typedef int hashed;

int n,i,j,k,t;
vector<int> a[10002];
vector<int> b[10002];
vector<vector<int>> d;
map<hashed, int> ca, cb;
int m;

bool is_same_vec(const vector<int> &a, const vector<int> &b){
    if(a.size() != b.size()) return false;
    for(int i=0;i<a.size();++i){
        if(a[i] != b[i]) return false;
    }
    return true;
}

bool vec_comparator(const vector<int> &a, const vector<int> &b){
    for(int i=0;i<a.size() && i<b.size();++i){
        if(a[i] < b[i]){
            return true;
        }
        else if(a[i] > b[i]){
            return false;
        }
    }
    return a.size() < b.size();
}

const int p = 103;
const int m1 = 1e9+7;
hashed hash_vec(const vector<int> &v){
    hashed res = 0;
    for(int x : v){
        res = (1LL * res * p + x + 1) % m1;
    }
    return res;
}

int main(){
	scanf("%d %d", &n, &m);
    for(int i=0;i<2*n;++i){
        scanf("%d", &t);
        int idx = i/2;
        if(i & 1){
            for(int j=0;j<t;++j){
                int x;
                scanf("%d", &x);
                b[idx].pb(x);
            }
            sort(b[idx].begin(), b[idx].end());
            cb[hash_vec(b[idx])]++;
        }
        else {
            for(int j=0;j<t;++j){
                int x;
                scanf("%d", &x);
                a[idx].pb(x);
            }
            sort(a[idx].begin(), a[idx].end());
            d.pb(a[idx]);
            ca[hash_vec(a[idx])]++;
        }
    }
    sort(d.begin(), d.end(), vec_comparator);
    d.erase(unique(d.begin(), d.end(), is_same_vec), d.end());
    int ans = 0;
    for(const vector<int> &x : d){
        hashed hc = hash_vec(x);
        if(cb.count(hc)){
            // cerr<<"1::"<<endl;
            // printArray(x);
            // printArray(x);
            // cerr<<"-> "<<ca[hc]<<" "<<cb[hc]<<endl;
            ans += ca[hc] * cb[hc];
        }
        // Removal
        for(int i=0;i<x.size();++i){
            vector<int> g;
            if(i){
                g.insert(g.end(), x.begin(), x.begin()+i);
            }
            if(i+1<x.size()){
                g.insert(g.end(), x.begin()+i+1, x.end());
            }
            hashed tmp = hash_vec(g);
            if(cb.count(tmp)){
                // cerr<<"2::"<<endl;
                // printArray(x);
                // printArray(g);
                // cerr<<"-> "<<ca[hc]<<" "<<cb[hc]<<endl;
                ans += ca[hc] * cb[tmp];
            }
        }
        // Adding
        for(int i=1;i<m;++i){
            int idx = lower_bound(x.begin(), x.end(), i) - x.begin();
            if(idx < x.size() && i == x[idx]){
                continue;
            }
            vector<int> g;
            if(idx == 0){
                g.pb(i);
                g.insert(g.end(), x.begin(), x.end());
            }
            else if(idx == x.size()){
                g.insert(g.end(), x.begin(), x.end());
                g.pb(i);
            }
            else {
                g.insert(g.end(), x.begin(), x.begin()+i);
                g.pb(i);
                g.insert(g.end(), x.begin()+i, x.end());
            }
            hashed tmp = hash_vec(g);
            if(cb.count(tmp)){
                // cerr<<"3::"<<endl;
                // printArray(x);
                // printArray(g);
                // cerr<<"-> "<<ca[hc]<<" "<<cb[hc]<<endl;
                ans += ca[hc] * cb[tmp];
            }
        }
    }
    printf("%d\n", ans);
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