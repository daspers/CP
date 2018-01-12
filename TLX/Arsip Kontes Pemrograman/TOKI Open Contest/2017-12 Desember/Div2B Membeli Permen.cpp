#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;

int n,j,k,p;
int a[55], b, c;
vector<int> r;


void permutate(int m, int c, int t){
	if(c == 0){
		r.pb(t);
		return;
	}
	for(int i=m;i<b;i++)
		permutate(i+1, c-1, t + a[i]);
}

int main(){
	scanf("%d %d %d", &n, &k, &p);
	for(int i=0;i<n;i++)
		scanf("%d", a+i);
	sort(a, a+n, greater<int>());
	b = min(p+k-1, n);
	permutate(0, k, 0);
	sort(r.begin(), r.end(), greater<int>());
	printf("%d\n", r[p-1]);
	return 0;
}
