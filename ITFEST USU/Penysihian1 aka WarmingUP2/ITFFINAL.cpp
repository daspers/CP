#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back+
#define pii pair<int, int>

typedef long long ll;

int const mod = 1e9+7;

int n,i,j,k,t;
int h,m,c,o,a;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d %d %d", &h,&c,&m, &o,&a);
		if(o<=c){
			puts("KO");
		}
		else if(h<=a){
			puts("IMPOSSIBLE");
		}
		else if(a>=m){
			n = ceil(1.0*h/a);
			k = ceil(1.0*o/c);
			if(k>n){
				puts("IMPOSSIBLE");
			}
			else{
				puts("POSSIBLE");
				printf("SERANG %d\n", k);
				puts("OBAT 0");
			}
			continue;
		}
		else{
			for(k=n=0;o>0;){
				if(h<=a && o>c){
					h+=m;
					n++;
				}
				else{
					o-=c;
					k++;
				}
				h-=a;
			}
			puts("POSSIBLE");
			printf("SERANG %d\n", k);
			printf("OBAT %d\n", n);
		}
	}
	return 0;
}
