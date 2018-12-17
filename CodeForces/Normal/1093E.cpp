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

const ll mod = 998244353 ;
const double PI = acos(-1);

int n,i,j,k,t;
int m;
int a[200005], b[200005];
int c[200005], d[200005], e[200005];
int atb[200005];
int bsz, bnum;
int st[500], ed[500];
int bit[448][200001];

inline int lastbit(int a){ return a&(-a); }

void updatebit(int num, int idx, int d){
    for(;idx<=n;idx+=lastbit(idx))
        bit[num][idx] += d;
}

int querybit(int num, int idx){
    int res = 0;
    while(idx > 0){
        res += bit[num][idx];
        idx -= lastbit(idx);
    }
    return res;
}

void eval(int num){
    for(i=st[num];i<ed[num];++i)
        updatebit(num, d[i], 1);
}

void update(int posa, int posb){
    updatebit(atb[c[b[posa]]], d[c[b[posa]]], -1);
    updatebit(atb[c[b[posa]]], d[c[b[posb]]], 1);
    updatebit(atb[c[b[posb]]], d[c[b[posb]]], -1);
    updatebit(atb[c[b[posb]]], d[c[b[posa]]], 1);
    swap(d[c[b[posa]]], d[c[b[posb]]]);
    swap(b[posa], b[posb]);
}

int query(int l, int r, int ql, int qr){
    int stb = atb[l];
    int edb = atb[r];
    int ans = 0;
    if(stb == edb){
        for(int i=l;i<=r;++i)
            ans += d[i]>=ql && d[i]<=qr;
    }
    else{
        if(st[atb[l]] == l)
            ans += querybit(atb[l], qr) - querybit(atb[l], ql-1);
        else{
            for(int i=l;i<ed[atb[l]];++i)
                ans += d[i]>=ql && d[i]<=qr;
        }
        for(int i=atb[l]+1;i<atb[r];++i)
            ans += querybit(i, qr) - querybit(i, ql-1);
        if(ed[atb[r]] == r)
            ans += querybit(atb[r], qr) - querybit(atb[r], ql-1);
        else{
            for(int i=st[atb[r]];i<=r;++i)
                ans += d[i]>=ql && d[i]<=qr;
        }
    }
    return ans;
}

void build(){
    memset(bit, 0, sizeof bit);
	bsz = sqrt(n);
	bnum = (n + bsz-1)/bsz;
	for(int i=0;i<bnum;++i){
		st[i] = i*bsz;
		ed[i] = min(st[i]+bsz, n);
		for(int j=st[i];j<ed[i];++j)
			atb[j] = i;
        eval(i);
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for(i=0;i<n;++i){
		scanf("%d", a+i);
		c[a[i]] = i;
	}
	for(i=1;i<=n;++i){
		scanf("%d", b+i);
		d[c[b[i]]] = i;
	}
	build();
	while(m--){
        int p;
        scanf("%d", &p);
        if(p==1){
            int p,q,r,s;
            scanf("%d %d %d %d", &p, &q, &r, &s);
            printf("%d\n", query(--p,--q,r,s));
        }
        else{
            int p, q;
            scanf("%d %d", &p, &q);
            update(p, q);
        }
    }
	return 0;
}