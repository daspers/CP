#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-9
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"

typedef long long ll;
typedef complex<double> cd;
typedef pair<int, int> pii;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
int q;
int a[50003], diff[50003];
pii tree[200020];
const pii dummyval = {-1e9, 1e9};

void build(int l, int r, int pos){
	if(l==r)
		tree[pos] = {diff[l], diff[l]};
	else{
		int mid = (l+r)>>1;
		build(l, mid, 2*pos+1);
		build(mid+1, r, 2*pos+2);
		tree[pos] = {max(tree[2*pos+1].fi,tree[2*pos+2].fi), min(tree[2*pos+1].se,tree[2*pos+2].se)};
	}
}

pii query(int l, int r, int pos, int ql, int qr){
	if(l>=ql && r<=qr)
		return tree[pos];
	if( r<ql || l > qr)
		return dummyval;
	int mid = (l+r)>>1;
	pii a = query(l, mid, 2*pos+1, ql, qr);
	pii b = query(mid+1, r, 2*pos+2, ql, qr);
	return {max(a.fi, b.fi), min(a.se, b.se)};
}

void update(int l, int r, int pos, int in){ //update tree
	if(l>in||r<in)
		return;
	if(l==r){
		tree[pos]={diff[l], diff[l]};
		return;
	}
	int mid = (l+r)/2;
	update(l, mid, 2*pos+1, in);
	update(mid+1, r, 2*pos+2, in);
	tree[pos] = {max(tree[2*pos+1].fi,tree[2*pos+2].fi), min(tree[2*pos+1].se,tree[2*pos+2].se)};
}

int main(){
	scanf("%d", &t);
	for(int cc=1;cc<=t;++cc){
		printf("Case #%d: ", cc);
		scanf("%d %d", &n, &q);
		for(i=0;i<n;++i)
			scanf("%d", a+i);
		for(i=0;i<n-1;++i)
			diff[i] = a[i+1]-a[i];
		if(n>2)
			build(0, n-2, 0);
		puts("");
		while(q--){
			int c, s, t;
			scanf("%d %d %d", &c, &s, &t);
			if(c==1){
				if(n>2){
					s--;
					int tmp = a[s] - t;
					a[s] = t;
					if(s>0){
						diff[s-1] -= tmp;
						update(0, n-2, 0, s-1);
					}
					if(s<n-1){
						diff[s] += tmp;
						update(0, n-2, 0, s);
					}
				}
			}
			else{
				s--, t--;
				if(n<=2 || t-s<2)
					puts("YES");
				else{
					pii res = query(0, n-2, 0, s, t-1);
					if(res.fi == res.se)
						puts("YES");
					else
						puts("NO");
				}
			}
		}
	}
	return 0;
}