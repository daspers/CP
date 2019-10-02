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
int m;
int a[200002];
int b[200002];
int p[200002];
vector<int> v[200002];
ll tree[800008];

void build(int l, int r, int pos){
    if(l == r){
        tree[pos] = b[l];
        return;
    }
    int mid = (l+r)/2;
    build(l, mid, 2*pos+1);
    build(mid+1, r, 2*pos+2);
    tree[pos] = tree[2*pos+1] + tree[2*pos+2];
}

int idx, val;
void update(int l, int r, int pos){
    if(r < idx || l > idx) return;
    if(l == r){
        tree[pos] = val;
        return;
    }
    int mid = (l+r)/2;
    update(l, mid, 2*pos+1);
    update(mid+1, r, 2*pos+2);
    tree[pos] = tree[2*pos+1] + tree[2*pos+2];
}

void print_tree(int l, int r, int pos){
    if(l == r){
        cerr<<l<<" "<<r<<" "<<pos<<" "<<tree[pos]<<endl;
        return;
    }
    int mid = (l+r)/2;
    print_tree(l, mid, 2*pos+1);
    print_tree(mid+1, r, 2*pos+1);
    cerr<<l<<" "<<r<<" "<<pos<<" "<<tree[pos]<<endl;
}


int main(){
	scanf("%d %d", &n, &m);
    ll sum = 0;
    for(int i=0;i<n;++i){
        p[i] = i;
    }
    for(int i=0;i<m;++i){
        scanf("%d", a+i);
        --a[i];
        v[a[i]].pb(i);
        if(i){
            b[i] = abs(p[a[i]] - p[a[i-1]]);
        }
    }
    build(1, m-1, 0);
    for(int i=0;i<n;++i){
        if(i){
            swap(p[i-1], p[i]);
            for(int x : v[i-1]){
                if(x > 0){
                    b[x] = abs(p[a[x]] - p[a[x-1]]);
                    idx = x;
                    val = b[x];
                    update(1, m-1, 0);
                }
                if(x + 1 < m){
                    b[x+1] = abs(p[a[x+1]] - p[a[x]]);
                    idx = x+1;
                    val = b[x+1];
                    update(1, m-1, 0);
                }
            }
            for(int x : v[i]){
                if(x > 0){
                    b[x] = abs(p[a[x]] - p[a[x-1]]);
                    idx = x;
                    val = b[x];
                    update(1, m-1, 0);
                }
                if(x + 1 < m){
                    b[x+1] = abs(p[a[x+1]] - p[a[x]]);
                    idx = x+1;
                    val = b[x+1];
                    update(1, m-1, 0);
                }
            }
        }
        printf("%lld ", tree[0]);
    }
    puts("");
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