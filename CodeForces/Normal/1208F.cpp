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
int a[1000002];
pii b[(1<<21)];

void add_mask(int val, int id){
    if(b[val].fi == id || b[val].se == id) return;
    if(b[val].fi == -1){
        b[val].fi = id;
    }
    else if(id > b[val].se) {
        b[val].se = id;
        if(b[val].fi < b[val].se)
            swap(b[val].fi, b[val].se);
    }
}

int main(){
	scanf("%d", &n);
    memset(b, -1, sizeof b);
    for(int i=0;i<n;++i){
        scanf("%d", a+i);
        add_mask(a[i], i);
    }
    for(int i=(1<<21) - 1;i>=0;--i){
        for(int j=1;j<(1<<21);j*=2){
            if(!(i&j)) {
                if(b[i^j].fi != -1){
                    add_mask(i, b[i^j].fi);
                }
                if(b[i^j].se != -1){
                    add_mask(i, b[i^j].se);
                }
            }
        }
    }
    // for(int i=(1<<21) - 1;i>=0;--i){
    //     if(b[i].se >= 0)
    //         printf("%d: %d %d\n", i, b[i].se, b[i].fi);
    // }
    int ans = a[0] | (a[1] & a[2]);
    for(int i=0;i<n-2;++i){
        int mask = 0;
        for(int j=1<<20;j>=1;j>>=1){
            if(a[i] & j) continue;
            if(b[mask | j].se > i) mask |= j;
        }
        // cerr<<a[i]<<" "<<mask<<endl;
        ans = max(ans, a[i] | mask);
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