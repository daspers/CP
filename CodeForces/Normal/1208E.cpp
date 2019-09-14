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
int len[1000002];
ll ans[1000002];
ll tree[4000008];
ll lazy[4000008];
int **a;
const int lb = -1e9;

void build(){
    memset(lazy, 0, sizeof lazy);
    memset(tree, 0, sizeof tree);
}

void update(int l, int r, int pos, int ql, int qr, int val){
    if(lazy[pos]){
        tree[pos] += lazy[pos];
        if(l!=r){
            lazy[2*pos+1] += lazy[pos];
            lazy[2*pos+2] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if(l > qr || r < ql) return;
    if(l>=ql && r<=qr){
        tree[pos] += val;
        if(l!=r){
            lazy[2*pos+1] += val;
            lazy[2*pos+2] += val;
        }
        return;
    }
    int mid = (l+r)/2;
    update(l, mid, 2*pos+1, ql, qr, val);
    update(mid+1, r, 2*pos+2, ql, qr, val);
    tree[pos] = tree[2*pos+1]+tree[2*pos+2];
}

void moveToAns(int l, int r, int pos){
    if(lazy[pos]){
        tree[pos] += lazy[pos];
        if(l!=r){
            lazy[2*pos+1] += lazy[pos];
            lazy[2*pos+2] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if(l == r){
        ans[l] = tree[pos];
        return;
    }
    int mid = (l+r)/2;
    moveToAns(l, mid, 2*pos+1);
    moveToAns(mid+1, r, 2*pos+2);
}

int main(){
	scanf("%d %d", &n, &m);
    build();
    a = new int*[n];
    for(int i=0;i<n;++i){
        scanf("%d", len+i);
        a[i] = new int[len[i] + 2];
        a[i][len[i]] = 0;
        priority_queue<pii> pq;
        pq.push({0, m - len[i] - 1});
        int lst = 0;
        for(int j=0;j<=len[i];++j){
            if(j < len[i]){
                scanf("%d", &a[i][j]);
            }
            while(!pq.empty() && pq.top().se < j){
                if(pq.top().se >= lst && pq.top().se < m && lst < m){
                    update(0, m-1, 0, lst, min(pq.top().se, m-1), pq.top().fi);
                    lst = min(pq.top().se, m-1) + 1;
                }
                pq.pop();
            }
            if(!pq.empty()){
                if(pq.top().fi < a[i][j] && lst < j){
                    update(0, m-1, 0, lst, j - 1, pq.top().fi);
                    lst = j;
                }
            }
            pq.push({a[i][j], j + m - len[i]});
        }
        while(!pq.empty()){
            if(pq.top().se >= lst && lst < m){
                update(0, m-1, 0, lst, min(pq.top().se, m-1), pq.top().fi);
                lst = min(pq.top().se + 1, m);
            }
            pq.pop();
        }
    }
    moveToAns(0, m-1, 0);
    for(int i=0;i<m;++i)
        printf("%lld ", ans[i]);
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