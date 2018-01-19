#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;

int const mod = 1e9+7;

int n,i,j,k,t,a,p=0;
vector<int> v;
set<vector<int>> s;

void permutate(int i, int j, vector<int> r){
	if(i+1>=n){
		sort(r.begin(), r.end());
		s.insert(r);
		return;
	}
	if(j>=n){
		permutate(i+1, i+2, r);
		return;
	}
	r[i]+=3;
	permutate(i,j+1,r);
	r[i]-=2;
	r[j]+=1;
	permutate(i,j+1,r);
	r[i]-=1;
	r[j]+=2;
	permutate(i,j+1,r);
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(i=0;i<n;i++){
			scanf("%d", &a);
			v.pb(a);
		}
		sort(v.begin(), v.end());
		if(p!=n){
			p = n;
			s.clear();
			vector<int> q(n, 0);
			permutate(0, 1, q);
		}
		if(s.find(v)!=s.end())
			puts("YES");
		else
			puts("NO");
		v.clear();
	}
	return 0;
}
