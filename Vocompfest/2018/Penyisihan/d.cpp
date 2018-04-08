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
int a;

int main(){
	scanf("%d", &t);
	for(int cc=1;t--;cc++){
		printf("Case #%d: ", cc);
		cin>>s;
		a = 0;
		for(i=0;i<s.size();i++){
			if(s[i]=='/'){
				printf("%c", (char) a+'A'-1);
				a=0;
			}
			else if(s[i] == '#'){
				printf(" ");
				a=0;
				i++;
			}
			else{
				a <<=1;
				if(s[i]=='-'){
					a+=1;
				}
			}
		}
		puts("");
	}
	return 0;
}