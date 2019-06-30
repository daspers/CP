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
char s[1000002];
int sum[1000002];
int tree[4000008];
int lazy[4000008];

void build(int l, int r, int pos){
    lazy[pos] = 0;
    if(l == r){
        tree[pos] = sum[l];
        return;
    }
    int mid=(l+r)/2;
    build(l, mid, 2*pos+1);
    build(mid+1, r, 2*pos+2);
    tree[pos] = max(tree[2*pos+1], tree[2*pos+2]);
}

void update(int l, int r, int pos, int idx){
    if(lazy[pos]){
        tree[pos] += lazy[pos];
        if(l!=r){
            lazy[2*pos+1] += lazy[pos];
            lazy[2*pos+2] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if(r < idx) return;
    if(l >= idx){
        tree[pos] -= 2;
        if(l!=r){
            lazy[2*pos+1]-=2;
            lazy[2*pos+2]-=2;
        }
        return;
    }
    int mid=(l+r)/2;
    update(l, mid, 2*pos+1, idx);
    update(mid+1, r, 2*pos+2, idx);
    tree[pos] = max(tree[2*pos+1], tree[2*pos+2]);
}

int query(int l, int r, int pos, int ql){
    if(lazy[pos]){
        tree[pos] += lazy[pos];
        if(l!=r){
            lazy[2*pos+1] += lazy[pos];
            lazy[2*pos+2] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if(r < ql) return -1000000;
    if(l >= ql){
        return tree[pos];
    }
    int mid=(l+r)/2;
    return max(
        query(l, mid, 2*pos+1, ql),
        query(mid+1, r, 2*pos+2, ql)
    );
}

int powmod(int b, int e){
    int ans = 1;
    for(;e;e>>=1){
        if(e & 1)
            ans = 1LL*ans*b %mod;
        b = 1LL*b*b % mod;
    }
    return ans;
}

int main(){
	scanf("%d", &t);
    for(int cc=1;cc<=t;++cc){
        scanf("%d %d", &n, &k);
        scanf("%s", s+1);
        sum[0] = 0;
        for(int i=1;i<=n;++i){
            sum[i] = sum[i-1] + (s[i]=='A'?-1:1);
        }
        build(1, n, 0);
        int ans = 0;
        for(int i=n;i>0;--i){
            if(s[i] == 'A') continue;
            int tmp = query(1, n, 0, i)-sum[i-1];
            if(tmp >= k+1){
                s[i] = 'A';
                update(1, n, 0, i);
                ans = (ans + powmod(2, i))%mod;
            }
        }
        printf("Case #%d: %d\n", cc, ans);
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