#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-9

typedef long long ll;
typedef complex<double> cd;
typedef pair<int, int> pii;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
int q, b[100002], ans[100002];
pii a[100002];
bool iscut[100002];
int parent[100002], sized[100002];

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    sized[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sized[a] < sized[b])
            swap(a, b);
        parent[b] = a;
        sized[a] += sized[b];
    }
}

int main(){
	memset(iscut, false, sizeof iscut);
	scanf("%d %d", &n, &k);
	for(i=0;i<k;++i){
		scanf("%d %d", &a[i].fi, &a[i].se);
		a[i].fi--;
		a[i].se--;
	}
	scanf("%d", &q);
	for(i=0;i<q;++i){
		scanf("%d", b+i);
		iscut[--b[i]] = true;
	}
	for(i=0;i<n;++i){
		make_set(i);
	}
	for(i=0;i<k;++i){
		if(iscut[i])
			continue;
		union_sets(a[i].fi, a[i].se);
	}
	set<int> s;
	for(i=0;i<n;++i){
		s.insert(find_set(i));
	}
	int numset = s.size();
	for(i=q-1;i>=0;--i){
		ans[i] = numset;
		if(find_set(a[b[i]].fi)!=find_set(a[b[i]].se))
			numset--;
		union_sets(a[b[i]].fi, a[b[i]].se);
	}
	for(i=0;i<q;++i)
		printf("%d ", ans[i]);
	puts("");
	return 0;
}