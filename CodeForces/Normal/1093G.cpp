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

const ll mod = 1e9+7;
const double PI = acos(-1);

int n,i,j,k,t;
int q;
vector<int> tree[800009];
int p[200002][5];
int ver[32][5];
int sz;

const int refer = 1e6;
int dist1(int a, int idx){
    int ans = 0;
    for(int i=0;i<k;++i)
        ans += abs(p[a][i] - ver[idx][i]);
    return ans;
}

int dist2(int a, int b){
    int ans = 0;
    for(int i=0;i<k;++i)
        ans += abs(p[a][i] - p[b][i]);
    return ans;
}

void combine(vector<int> &a, const vector<int> &b, const vector<int> &c){
    for(int i=0;i<sz;++i){
        int db = dist1(b[i], i);
        int dc = dist1(c[i], i); 
        if(db > dc)
            a[i] = c[i];
        else a[i] = b[i];
    }
}

void build(int l, int r, int pos){
    if(l == r){
        for(int i=0;i<sz;++i)
            tree[pos].pb(l);
        return;
    }
    int mid = (l+r)/2;
    build(l, mid, 2*pos+1);
    build(mid+1, r, 2*pos+2);
    tree[pos].resize(sz);
    combine(tree[pos], tree[2*pos+1], tree[2*pos+2]);
}

void update(int l, int r, int pos, int idx){
    if(l > idx || r < idx || l == r) return;
    int mid = (l+r)/2;
    update(l, mid, 2*pos+1, idx);
    update(mid+1, r, 2*pos+2,  idx);
    combine(tree[pos], tree[2*pos+1], tree[2*pos+2]);
}

vector<int> query(int l, int r, int pos, int ql, int qr){
    if(l > qr || r < ql)
        return vector<int>();
    if(l>=ql && r<=qr)
        return tree[pos];
    int mid = (l+r)/2;
    vector<int> a = query(l, mid, 2*pos+1, ql, qr);
    vector<int> b = query(mid+1, r, 2*pos+2, ql, qr);
    if(a.size() == 0)
        return b;
    if(b.size() == 0)
        return a;
    vector<int> ans(sz);
    combine(ans, a, b);
    return ans;
}

void generate(){
    int R = sz;
    int L = sz >> 1;
    for(int i=0;i<k;++i){
        for(int j=0;j<sz;++j)
            ver[j][i] = ((j%R) < L ? -1 : 1) * refer;
        L >>=1;
        R >>=1;
    }
}

int main(){
    scanf("%d %d", &n, &k);
    sz = 1<<k;
    generate();
    for(i=0;i<n;++i){
        for(j=0;j<k;++j)
            scanf("%d", p[i]+j);
    }
    build(0, n-1, 0);
    scanf("%d", &q);
    while(q--){
        int c;
        scanf("%d", &c);
        if(c==1){
            int idx;
            scanf("%d", &idx);
            --idx;
            for(i=0;i<k;++i)
                scanf("%d", p[idx]+i);
            update(0, n-1, 0, idx);
        }
        else{
            int l, r, ans = 0;
            vector<int> tmp;
            scanf("%d %d", &l, &r);
            tmp = query(0, n-1, 0, --l ,--r);
            for(i=0;i<sz-1;++i)
                for(j=i+1;j<sz;++j)
                    ans = max(ans, dist2(tmp[i], tmp[j]));
            printf("%d\n", ans);
        }
    }
    return 0;
}