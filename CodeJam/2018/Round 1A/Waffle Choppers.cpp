#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
 
const ll mod = 8;
const double pi = acos(-1);
 
int n,t,i,j,k;
int m,x,y;
string s[101];
int c[101], d[101], tot;

int main(){
	scanf("%d", &t);
	for(int cc=1;t--;cc++){
		printf("Case #%d: ", cc);
		memset(c, 0, sizeof c);
		memset(d, 0, sizeof d);
		tot = 0;
		scanf("%d %d %d %d", &n, &m, &x, &y);
		for(i=0;i<n;i++){
			cin>>s[i];
		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(s[i][j]=='@'){
					tot++;
					c[i]++;
					d[j]++;
				}
			}
		}
		if(tot%((x+1)*(y+1))){
			puts("IMPOSSIBLE");
		}
		else{
			int hor = tot / (x+1);
			int ver = tot / (y+1);
			int temp=0;
			int cal = tot/(x+1)/(y+1);
			int sti=0, stj=0;
			vector<int> hv, vv;
			for(i=0;i<n;i++){
				temp += c[i];
				if(temp == hor){
					temp = 0;
					hv.pb(i+1);
				}
				else if(temp > hor){
					puts("IMPOSSIBLE");
					goto cabut;
				}
			}
			for(i=0;i<m;i++){
				temp += d[i];
				if(temp == ver){
					temp = 0;
					vv.pb(i+1);
				}
				else if(temp > ver){
					puts("IMPOSSIBLE");
					goto cabut;
				}
			}
			for(int& v : hv){
				stj = 0;
				for(int& w : vv){
					int hit=0;
					for(i=sti;i<v;i++){
						for(j=stj;j<w;j++){
							if(s[i][j]=='@')
								hit++;
						}
					}
					if(hit!=cal){
						puts("IMPOSSIBLE");
						goto cabut;
					}
					stj = w;
				}
				sti = v;
			}
			puts("POSSIBLE");
			cabut:;
		}
	}
	return 0;
} 