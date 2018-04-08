/*
	WARNING!!!
	WRONG SOLUTION
*/

#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,t,i,j,k;
string s;
int a[101], c, tot;
int b[101];

int main(){
	scanf("%d", &t);
	for(int cc=1;t--;cc++){
		printf("Case #%d: ", cc);
		cin>>s;
		s = "0"+s;
		a[0]=0;
		c = 0;
		tot = 0;
		for(i=1;i<s.size();i++){
			a[i] = a[i-1];
			a[i] += s[i]=='A';
		}
		for(i=1;i<s.size();i++){
			if(s[i]=='B'){
				c++;
				tot += a[i];
			}
		}
		if(c==0)
			puts("Semar");
		else if(c==1)
			puts("Gareng");
		else if(c==2){
			if(tot&1)
				puts("Gareng");
			else
				puts("Semar");
		}
		else if(tot==0){
			if(c&1)
				puts("Gareng");
			else
				puts("Semar");
		}
		else if(tot % c){
			puts("Gareng");
		}
		else{
			puts("Semar");
		}
			
	}
	return 0;
}