#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define INF 200000001
#define EPS 1e-9

typedef long long ll;
typedef complex<double> cd;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
int a, b;
char mep[1000][1000];

int main(){
	memset(mep, '0', sizeof mep);
	scanf("%d %d %d", &n, &a, &b);
	if(min(a, b)!=1){
		puts("NO");
		return 0;
	}
	if(n <= 3){
		if(n==1){
			puts("YES\n0");
		}
		else if(n==2){
			if(a==1 && b==2){
				puts("YES\n01\n10");
			}
			else if(a==2&&b==1){
				puts("YES\n00\n00");
			}
			else
				puts("NO");
		}
		else if(n==3){
			if(a==1&&b==2){
				puts("YES\n011\n100\n100");
			}
			else if(a==2&&b==1){
				puts("YES\n010\n100\n000");
			}
			else if(a==1&&b==3){
				puts("YES\n011\n101\n110");
			}
			else if(a==3&&b==1){
				puts("YES\n000\n000\n000");
			}
			else
				puts("NO");
		}
		return 0;
	}
	bool inv = false;
	if(a < b){
		swap(a, b);
		inv = true;
	}
	for(i=n;i>a;--i){
		mep[n-i][n-i+1] = mep[n-i+1][n-i] = '1';
	}
	if(inv){
		for(i=0;i<n;++i){
			for(j=0;j<n;++j)
				if(i!=j){
					mep[i][j] = '0'+!(mep[i][j]-'0');
				}
		}
	}
	puts("YES");
	for(i=0;i<n;++i){
		for(j=0;j<n;++j)
			printf("%c", mep[i][j]);
		puts("");
	}
	return 0;
}