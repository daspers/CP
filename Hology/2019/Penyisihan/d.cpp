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
int a[300004];
char tree[1200012], dp[300004];

int ql, qr;
void update(int l, int r, int pos){
    if(l>ql || r<ql) return;
    if(l == r) {
        tree[pos] = 1;
        return;
    }
    int mid = (l+r)/2;
    update(l, mid, 2*pos+1);
    update(mid+1, r, 2*pos+2);
    tree[pos] = max(tree[2*pos+1], tree[2*pos+2]);
}

void build(){
    memset(tree, 0, sizeof tree);
    memset(dp, 0, sizeof dp);
    ql = n;
    update(0, n, 0);
}

int query(int l, int r, int pos){
    if(l > qr || r < ql) return 0;
    if(l >= ql && r <= qr) return tree[pos];
    int mid = (l+r)/2;
    return max(
        query(l, mid, 2*pos+1),
        query(mid+1, r, 2*pos+2)
    );
}

int main(){
	scanf("%d %d", &n, &k);
    for(int i=0;i<n;++i)
        scanf("%d", a+i);
    sort(a, a+n);
    a[n] = a[n-1];
    int l = 0, r = (int)1e9 - 1;
    while(l<r){
        int mid = (l+r)/2;
        build();
        for(int i=n-k;i>=0;--i){
            ql = i + k;
            qr = min((int)(upper_bound(a, a+n+1, a[i]+mid) - a), n);
            if (ql > qr || ql > n) continue;
            dp[i] = query(0, n, 0);
            if(dp[i]){
                ql = i;
                update(0, n, 0);
            }
        }
        if(dp[0]){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    printf("%d\n", r);
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