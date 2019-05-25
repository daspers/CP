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
pii a[300002];
pair<pii, int> b[300002];
int pos[300002];
pii tree[1200003];

void build(int l, int r, int pos){
    if(l == r){
        tree[pos] = {b[l].fi.fi, b[l].se};
        return;
    }
    int mid = (l+r)/2;
    build(l, mid, 2*pos+1);
    build(mid+1, r, 2*pos+2);
    tree[pos] = max(tree[2*pos+1], tree[2*pos+2]);
}

void update(int l, int r, int pos, int idx, int val){
    if(r < idx || l > idx) return;
    if(l == r){
        tree[pos].fi = val;
        return;
    }
    int mid = (l+r)/2;
    update(l, mid, 2*pos+1, idx, val);
    update(mid+1, r, 2*pos+2, idx, val);
    tree[pos] = max(tree[2*pos+1], tree[2*pos+2]);
}

pii query(int l, int r, int pos, int ql, int qr){
    if(r < ql || l > qr) return {0, 0};
    if(l >= ql && r <= qr) return tree[pos];
    int mid = (l+r)/2;
    return max(
        query(l, mid, 2*pos+1, ql, qr),
        query(mid+1, r, 2*pos+2, ql, qr)
    );
}

int get(int val){
    return upper_bound(b, b+n, val, [](int a, const pair<pii, int> b){
        return a < b.fi.se;
    }) - b - 1;
}

int main(){
	scanf("%d", &n);
    for(int i=0;i<n;++i){
        scanf("%d %d", &a[i].fi, &a[i].se);
        b[i] = {a[i], i};
    }
    sort(b, b+n, [](const pair<pii, int> &a, const pair<pii, int> &b){
        if(a.fi.se == b.fi.se){
            return a.fi.fi > b.fi.fi;
        }
        return a.fi.se < b.fi.se;
    });
    for(int i=0;i<n;++i){
        pos[b[i].se] = i;
    }
    build(0, n-1, 0);
    int ans = 0;
    pii wew = {1, 2};
    for(int i=0;i<n;++i){
        update(0, n-1, 0, pos[i], 0);
        int x = get(a[i].fi);
        if(x >= 0) {
            pii att = query(0, n-1, 0, 0, x);
            if(att.fi > 0 && att.se != i){
                int tmp = att.fi;
                if(att.fi >= a[i].se){
                    tmp += a[i].fi;
                }
                if(tmp > ans){
                    // cerr<<i<<" "<<att.fi<<" "<<att.se<<endl;
                    ans = tmp;
                    wew = {i+1, att.se+1};
                }
            }
        }
        update(0, n-1, 0, pos[i], a[i].fi);
    }
    printf("%d\n", ans);
    printf("%d %d\n", wew.fi, wew.se);
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