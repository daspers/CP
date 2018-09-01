#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-8
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
char s[10];
int cnt[4][13];

int main(){
	scanf("%d", &t);
	while(t--){
		memset(cnt, 0, sizeof cnt);
		scanf("%d", &n);
		for(i=0;i<n;++i){
			scanf("%s", s);
			k = strlen(s);
			int tmp = 9;
			int awal = 0;
			if(s[k-1] == 'H')
				awal = 1;
			else if(s[k-1] == 'D')
				awal = 2;
			else if(s[k-1] == 'C')
				awal = 3;
			if(k == 2){
				if(s[0]>='2' && s[0] <= '9')
					tmp = s[0]-'1';
				else{
					if(s[0]=='A')
						tmp = 0;
					else if(s[0]=='J')
						tmp = 10;
					else if(s[0] =='Q')
						tmp = 11;
					else 
						tmp = 12;
				}
			}
			// cout<<awal <<" "<<tmp<<endl;
			cnt[awal][tmp] ++;
		}
		bool bisa = true;
		for(i=0;i<4;++i){
			if(*min_element(cnt[i], cnt[i]+13) < 1)
				bisa = false;
		}
		if(bisa)
			printf("FULLHOUSE %d\n", n-52);
		else 
			puts("INCOMPLETE");
	}
	return 0;
}