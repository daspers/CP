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
ll a[200002];
int ans[200002];
ll tree[800010];

void build(int l, int r, int pos){
    if(l == r){
        tree[pos] = l;
        return;
    }
    int mid = (l+r)/2;
    build(l, mid, 2*pos+1);
    build(mid+1, r, 2*pos+2);
    tree[pos] = tree[2*pos+1] + tree[2*pos+2];
}

void update(int l, int r, int pos, int idx){
    if(l > idx || r < idx) return;
    if(l == r){
        tree[pos] = 0;
        return;
    }
    int mid = (l+r)/2;
    update(l, mid, 2*pos+1, idx);
    update(mid+1, r, 2*pos+2, idx);
    tree[pos] = tree[2*pos+1] + tree[2*pos+2];
}

ll query(int l, int r, int pos, int qr){
    if(l>qr) return 0;
    if(r <= qr) return tree[pos];
    int mid = (l+r)/2;
    return query(l, mid, 2*pos+1, qr) + query(mid+1, r, 2*pos+2, qr);
}

int main(){
	scanf("%d", &n);
    for(int i=0;i<n;++i)
        scanf("%lld", a+i);
    build(0, n-1, 0);
    set<int> wew;
    for(int i=1;i<=n;++i){
        wew.insert(i);
    }
    for(int i=n-1;i>=0;--i){
        int l = 0, r = n-1;
        ll sum;
        while(l < r){
            int mid = (l+r+1)/2;
            // cerr<<l<<" "<<r<<" "<<mid<<endl;
            sum = query(0, n-1, 0, mid);
            if(sum > a[i]){
                r = mid-1;
            }
            else{
                l = mid;
            }
        }
        set<int>::iterator it = wew.upper_bound(l+1);
        assert(it != wew.begin());
        --it;
        ans[i] = *it;
        wew.erase(it);
        if(ans[i] < n){
            update(0, n-1, 0, ans[i]);
        }
    }
    for(int i=0;i<n;++i)
        printf("%d ", ans[i]);
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