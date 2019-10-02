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

struct cc {
    int c[26];
    void reset(){
        memset(c, 0, sizeof c);
    }
};

int n,i,j,k,t;
char s[100004];
int lazy[400004];
cc tree[400004];
int q;

void build(int l, int r, int pos){
    if(l == r){
        tree[pos].reset();
        tree[pos].c[s[l]-'a']++;
        return;
    }
    int mid = (l+r)/2;
    build(l, mid, 2*pos+1);
    build(mid+1, r, 2*pos+2);
    for(int i=0;i<26;++i){
        tree[pos].c[i] = tree[2*pos+1].c[i] + tree[2*pos+2].c[i];
    }
}

int ql, qr, val;
void update(int l, int r, int pos){
    if(lazy[pos] != -1){
        tree[pos].reset();
        tree[pos].c[lazy[pos]] = r - l +1;
        if(l != r){
            lazy[2*pos+1] = lazy[pos];
            lazy[2*pos+2] = lazy[pos];
        }
        lazy[pos] = -1;
    }
    if(r < ql || l > qr){
        return;
    }
    if(l>=ql && r<=qr){
        tree[pos].reset();
        tree[pos].c[val] = (r - l + 1);
        if(l != r){
            lazy[2*pos+1] = val;
            lazy[2*pos+2] = val;
        }
        lazy[pos] = -1;
        return;
    }
    int mid = (l+r)/2;
    update(l, mid, 2*pos+1);
    update(mid+1, r, 2*pos+2);
    for(int i=0;i<26;++i){
        tree[pos].c[i] = tree[2*pos+1].c[i] + tree[2*pos+2].c[i];
    }
}

cc query(int l, int r, int pos){
    if(lazy[pos] != -1){
        tree[pos].reset();
        tree[pos].c[lazy[pos]] = r - l +1;
        if(l != r){
            lazy[2*pos+1] = lazy[pos];
            lazy[2*pos+2] = lazy[pos];
        }
        lazy[pos] = -1;
    }
    if(r < ql || l > qr){
        cc x;
        x.reset();
        return x;
    }
    if(l>=ql && r<=qr){
        return tree[pos];
    }
    int mid = (l+r)/2;
    cc a = query(l, mid, 2*pos+1);
    cc b = query(mid+1, r, 2*pos+2);
    cc res;
    for(int i=0;i<26;++i){
        res.c[i] = a.c[i] + b.c[i];
    }
    return res;
}

int main(){
	scanf("%s", s);
	scanf("%d", &q);
    n = strlen(s);
    // cerr<<"a"<<endl;
    memset(lazy, -1, sizeof lazy);
    build(0, n-1, 0);
    // cerr<<"b"<<endl;
    while(q--){
        int p;
        scanf("%d", &p);
        if(p == 1){
            char c;
            scanf("%d %c", &ql, &c);
            val = c - 'a';
            qr = --ql;
            // cerr<<"read"<<" "<<ql<<" "<<val<<endl;
            update(0, n-1, 0);
        }
        else {
            scanf("%d %d", &ql, &qr);
            --ql; --qr;
            cc res = query(0, n-1, 0);
            // cerr<<"read"<<" "<<ql<<" "<<qr<<endl;
            int ans = 0;
            for(int i=0;i<26;++i){
                ans += res.c[i] > 0;
                // cerr<<res.c[i]<<" ";
            }
            // cerr<<endl;
            printf("%d\n", ans);
        }
    }
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