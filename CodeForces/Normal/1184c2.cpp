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
int rad;
pii p[300002], q[300002];
vector<int> adj[4000002], v;
const int z = 2e6;
int tree[16000020];
int lazy[16000020];

void build(){
    memset(tree, 0, sizeof tree);
    memset(lazy, 0, sizeof lazy);
}

int ql, qr, val;
void update(int l, int r, int pos){
    if(lazy[pos]) {
        tree[pos] += lazy[pos];
        if(l!=r){
            lazy[2*pos+1] += lazy[pos];
            lazy[2*pos+2] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if(l > qr || r < ql) return;
    // cerr<<l<<" "<<r<<" "<<pos<<" "<<ql<<" "<<qr<<" "<<(l>=ql && r<=qr)<<endl;
    if(l>=ql && r<=qr){
        tree[pos]+=val;
        if(l!=r){
            lazy[2*pos+1] += val;
            lazy[2*pos+2] += val;
        }
        return;
    }
    // cerr<<l<<" "<<r<<" "<<pos<<" "<<ql<<" "<<qr<<endl;
    int mid = (l+r)/2;
    update(l, mid, 2*pos+1);
    update(mid+1, r, 2*pos+2);
    tree[pos] = max(tree[2*pos+1], tree[2*pos+2]);
}

int query(int l, int r, int pos){
    if(lazy[pos]) {
        tree[pos] += lazy[pos];
        if(l!=r){
            lazy[2*pos+1] += lazy[pos];
            lazy[2*pos+2] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    return tree[pos];
}

// void print(int l, int r, int pos){
//     if(lazy[pos]) {
//         tree[pos] += lazy[pos];
//         if(l!=r){
//             lazy[2*pos+1] += lazy[pos];
//             lazy[2*pos+2] += lazy[pos];
//         }
//         lazy[pos] = 0;
//     }
//     if(l > qr || r < ql) return;
//     if(l == r) {
//         cout<<l-z<<" "<<tree[pos]<<endl;
//         return;
//     }
//     int mid = (l+r)/2;
//     print(l, mid, 2*pos+1);
//     print(mid+1, r, 2*pos+2);
// }

int main(){
	scanf("%d %d", &n, &rad);
    for(int i=0;i<n;++i){
        scanf("%d %d", &p[i].fi, &p[i].se);
        q[i].fi = p[i].fi+p[i].se;
        q[i].se = p[i].fi-p[i].se;
        // cout<<q[i].fi<<" "<<q[i].se<<endl;
    }
    sort(q, q+n);
    for(int i=0;i<n;++i){
        adj[z + q[i].fi].pb(q[i].se);
        v.pb(q[i].fi);
    }
    v.erase(unique(v.begin(), v.end()), v.end());
    int l, r;
    int ans = 1;
    // cerr<<v.size()<<endl;
    for(l=0,r=0;r<v.size();++l){
        val = 1;
        while(r < v.size() && v[r] - v[l] <= 2*rad){
            // cerr<<"> "<<2*rad<<" "<<v[r]<<" "<<v[l]<<" "<<v[r]-v[l]<<endl;
            for(int x : adj[v[r]+z]){
                ql = max(x - rad + z, 0);
                qr = min(x + rad + z, 2*z);
                // cerr<<"heh "<<ql<<" "<<ql<<endl;
                update(0, 2*z, 0);
            }
            ++r;
        }
        // cerr<<"woi "<<l<<" "<<r<<" "<<v[l]<<" "<<v[r-1]<<endl;
        ql = z - 4;
        qr = z + 4;
        ans = max(ans, query(0, 2*z, 0));
        val = -1;
        for(int x : adj[v[l]+z]){
            ql = max(x - rad + z, 0);
            qr = min(x + rad + z, 2*z);
            update(0, 2*z, 0);
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