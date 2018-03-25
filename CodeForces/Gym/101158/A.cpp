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

unordered_set<int> s;
int c[200002];
bool sudah[200002];

int main(){
	int n,m;
	memset(sudah, true, sizeof sudah);
	scanf("%d %d", &n, &m);
	for(int i=0;i<m;i++){
		scanf("%d", c+i);
	}
	reverse(c, c+m);
	for(int i=0;i<m;i++){
		if(sudah[c[i]]){
			printf("%d\n", c[i]);
			sudah[c[i]] = false;
		}
	}
	for(int i=1;i<=n;i++){
		if(sudah[i]){
			printf("%d\n", i);
			sudah[i] = false;
		}
	}
	return 0;
};