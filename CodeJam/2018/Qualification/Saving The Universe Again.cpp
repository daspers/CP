#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef unsigned long long ull;
 
const ll mod = 1e9+7;
const double pi = acos(-1);

int n,t,j,i,k;
string s;
int hit;
int dam[30];

int main(){
	scanf("%d", &t);
	for(int cc=1;t--;cc++){
		cin>>n>>s;
		s = "0"+s+"0";
		int tot=0;
		dam[0] = 1;
		for(i=1;i<s.size()-1;i++){
			dam[i] = dam[i-1];
			if(s[i]=='C')
				dam[i] <<=1;
			else
				tot+=dam[i];
		}
		int hack = 0;
		for(i=s.size()-2;i>1&&tot>n;i--){
			if(s[i]=='S'){
				if(s[i-1]=='C'){
					swap(s[i], s[i-1]);
					dam[i-1]>>=1;
					tot -= dam[i-1];
					hack++;
					i+=2;
				}
			}
		}
		printf("Case #%d: ", cc);
		if(tot>n)
			puts("IMPOSSIBLE");
		else
			printf("%d\n", hack);
	}
	return 0;
}