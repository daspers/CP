#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define fi first
#define se second

pair<int, int> a[15];
bool  b[266];
int n,i,t,j,m;
char c;


int main()
{
	FILE *F;
	F = fopen("scoreboard.in", "r");
	fscanf(F,"%d", &t);
	while(t--){
		fscanf(F, "%d\n", &n);
		memset(b, 0, sizeof(b));
		for (i=0;i<n;i++){
			fscanf(F, "%c", &c);
			b[c] = 1;
		}
		for(i=0;i<13;i++){
			fscanf(F, "%d", &m);
			a[i] = mp(m, 'A'+i);
		}
		sort(a, a+13, greater<pair<int,int> >());
		for(i=0;i<13;i++){
			if(!b[a[i].se]){
				printf("%c\n", a[i].se);
				break;
			}
		}
	}
}