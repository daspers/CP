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
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
int m;
ll dist[1000002];
vector<int> nd[2000005];
vector<ll> psum[1000005];

void fill(int node){
	if(node > n)
		return;
	fill(2*node);
	fill(2*node+1);
	nd[node].pb(node);
	vector<int> &a = nd[2*node], &b = nd[2*node+1];
	int i=0,j=0;
	while(i<a.size() && j<b.size()){
		if(dist[a[i]] < dist[b[j]])
			nd[node].pb(a[i++]);
		else
			nd[node].pb(b[j++]);
	}
	while(i<a.size())
		nd[node].pb(a[i++]);
	while(j<b.size())
		nd[node].pb(b[j++]);
	ll sum = 0;
	for(int x : nd[node]){
		sum += dist[x];
		psum[node].pb(sum);
	}
}

ll getdown(int idx, int val){
	vector<int> &a = nd[idx];
	int sz = lower_bound(a.begin(), a.end(), val+dist[idx], [](const int &a, const ll &b){
		return dist[a] < b;
	}) - a.begin();
	// cout<<"down : "<<idx<<" "<<val<<" "<<sz<<endl;
	// cout<<"arr : ";
	// for(int x : a)
		// cout<<dist[x]<<" ";
	// cout<<endl;
	// cout<<1LL*sz*val<<" "<<psum[idx][sz-1]<<" "<<sz*dist[idx]<<endl;
	return 1LL*sz*val - (psum[idx][sz-1] - sz*dist[idx]);
}

ll getup(int ot, int idx, int val){
	ll res = val;
	if(ot <= n && dist[ot] - dist[idx] < val)
		res += getdown(ot, val - dist[ot] + dist[idx]);
	if(idx>1 && dist[idx] - dist[idx/2] < val)
		res += getup(idx^1, idx/2, val - dist[idx] + dist[idx/2]);
	return res;
}

ll get(int idx, int val){
	if(idx>1 && dist[idx] - dist[idx/2] < val)
		return getdown(idx, val) + getup(idx^1, idx/2, val - dist[idx] + dist[idx/2]);
	else
		return getdown(idx, val);
}

int main(){
	scanf("%d %d", &n, &m);
	for(i=2;i<=n;++i){
		int x;
		scanf("%d", &x);
		dist[i] = x;
	}
	dist[1] = 0;
	for(i=4;i<=n;++i)
		dist[i] += dist[i/2];
	fill(1);
	while(m--){
		int st, l;
		scanf("%d %d", &st, &l);
		printf("%lld\n", get(st, l));
	}
	return 0;
}