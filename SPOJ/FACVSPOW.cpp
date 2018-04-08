#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
 
const ll mod = 1e9+7;
const double pi = acos(-1);

int n,t,j,i,k,m;
int a, b, c;
double pol[10000005];
double w;

bool cmpit(int b){
	double x = w*b;
	return x < pol[b];
}

int main(){
	pol[1] = 0;
	for(i=2;i<=1e7;i++)
		pol[i]=pol[i-1]+log(i);
	scanf("%d", &t);
	while(t--){
		scanf("%d", &a);
		w = log(a);
		int l = a;
		int r = 1e7;
		int mid = (l+r)>>1;
		while(l<r){
			if(cmpit(mid))
				r = mid;
			else
				l = mid+1;
			mid = (l+r)>>1;
		}
		printf("%d\n", l);
	}
	return 0;
}