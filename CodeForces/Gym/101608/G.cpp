#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pr(x) x==1? n:x-1;
#define ne(x) x==n? 1:x+1;
 
typedef long long ll;
 
const ll mod = 1e9+7;
const double pi = acos(-1);
 
int t,n,k,x,j,i, ma;
int tree[400002];
int l,r,mid;
FILE *F;

void createsegtree(int l, int r, int pos){
	if(l==r){
		fscanf(F, "%d", tree+pos);
		// scanf("%d", tree+pos);
		return;
	}
	int mid = (l+r)/2;
	createsegtree(l, mid, 2*pos+1);
	createsegtree(mid+1, r, 2*pos+2);
	tree[pos] = tree[2*pos+1]|tree[2*pos+2]; // can be change depend on problems
}

int result(int l, int r, int ql, int qr, int pos){ //get answer to the problem
	if(l>=ql && r<=qr)
		return tree[pos];
	if(r<ql || l > qr)
		return 0;
	int mid = (l+r)/2;
	return result(l,mid,ql,qr,2*pos+1)|result(mid+1, r, ql, qr, 2*pos+2);
}

int main(){
	F = fopen("wifi.in","r");
    fscanf(F, "%d", &t);
	// scanf("%d", &t);
	while(t--){
		fscanf(F, "%d %d",&n, &k);
		// scanf("%d %d", &n, &k);
		createsegtree(0,n-1,0);
		for(ma=i=0;i<n;i++){
			l = i;
			r = n-1;
			while(l<=r){
				mid = (l+r)>>1;
				if(result(0,n-1,i,mid,0)<=k){
					l = mid+1;
					ma = max(ma, mid - i+1);
				}
				else
					r = mid-1;
			}
			if(i+ma>=n)
				break;
		}
		printf("%d\n", ma);
	}
    return 0;
}