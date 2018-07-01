#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;

int const mod = 1e9+7;

int n,i,j,k,t,p;
int a[10003];

void bf(int idx, int take, vector<int> &r){
	if(r.size() >= p)
		return;
	if(idx+take == n){
		if(r.size()!=p-1)
			return;
		printf("%d", r[0]);
		for(int i=1;i<r.size();i++)
			printf(" %d", r[i]);
		printf("\n");
		exit(0);
	}
	if(idx+take > n || a[idx+take] == a[idx+take-1])
		return;
	r.pb(a[idx+take]);
	bf(idx+take, k, r);
	bf(idx+take, k+1, r);
	r.pop_back();
}

int main(){
	scanf("%d", &n);
	for(i=0;i<n;i++)
		scanf("%d", a+i);
	scanf("%d", &p);
	sort(a, a+n);
	vector<int> tmp;
	k = n/p;
	bf(0, k, tmp);
	bf(0, k+1, tmp);
	return 0;
}