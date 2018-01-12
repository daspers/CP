#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

int n,i,j,k,t;
long double a,b,c;
pair<long double, long double> p[6];
set<long double> v;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(i=0;i<n;i++)
			cin>>p[i].fi>>p[i].se;
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				v.insert(3*pow(p[i].fi-p[j].fi,2)+pow(p[i].se-p[j].se,2));
			}
		}
		if(find(v.begin(), v.end(),0)!=v.end())
			puts("TIDAK");
		else if(n<3)
			puts("BISA");
		else{
			if(v.size()==1){
				puts("BISA");
				goto bisa;
			}
			else if(v.size()<=3){
				auto x = v.begin();
				a = *x;
				++x;
				b = *x;
				++x;
				if(v.size()==3){
					c = *x;
					if(b == 3*a&&c==4*a){
						puts("BISA");
						goto bisa;
					}
				}
				else if(n==3){
					if(b == 3*a){
						puts("BISA");
						goto bisa;
					}
				}
			}
			puts("TIDAK");
			bisa:;
		}
		v.clear();
	}
	return 0;
}
