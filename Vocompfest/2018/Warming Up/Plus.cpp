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
pair<int, int> p[100002];
bool sudah[100002];

void ver(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf(" ");
		}
		puts("*");
	}
}

int main(){
	scanf("%d",&n);
	ver();
	for(i=0;i<=2*n;i++)
		printf("*");
	puts("");
	ver();
	return 0;
}