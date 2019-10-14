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

void f(int l, int r){
    r -= l;
    l = 0;
    vector<int> v(r-l+1, 0);
    for(int i=l;i<=r;++i){
        for(int j=i;j<=r;++j){
            for(int k=i;k<=j;++k){
        // cerr<<i<<" "<<j<<" "<<k<<endl;
                v[k]++;
            }
        }
    }
    for(int i=l;i<=r;++i){
        cerr<<v[i]<<" ";
    }
    cerr<<endl;
}

int main(){
	scanf("%d", &n);
    // f(0, n);
    vector<int> v;
    v.pb(0);
    v.pb(0);
    v.pb(0);
    v.pb(0);
    v.pb(0);
    v.pb(1);
    v.pb(1);
    int cnt = 0;
    do{
        cnt++;
        printArray(v);
    }while(next_permutation(v.begin(), v.end()));
    debug(cnt);
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