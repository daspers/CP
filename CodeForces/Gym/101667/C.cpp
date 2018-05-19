#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int n, m;
int a, b, ans;
vi v[100001];
int banyak[1000001];

void dfs(int w){
	banyak[w] = 1;
	for(int & i:v[w]){
		if(v[i].size() > v[w].size()){
			if(banyak[i] == -1){
				dfs(i);
			}
			banyak[w] = max(banyak[w], 1+banyak[i]);
		}
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i=0;i<m;i++){
		scanf("%d %d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}
	memset(banyak, -1,sizeof  banyak);
	for(int i =0;i<n;i++){
		int tmp;
		if(banyak[i]==-1){
			dfs(i);
		}
		tmp = banyak[i];
		ans = max(ans, tmp);
	}
	printf("%d\n", ans);
	return 0;
};