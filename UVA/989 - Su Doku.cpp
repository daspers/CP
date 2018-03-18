#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
 
const ll mod = 1e9+7;
const double pi = acos(-1);

int n,t,j,i,k;
int g[10][10];

bool cek(int x, int y, int val){
	for(int i=0;i<n*n;i++){
		if(i!=x){
			if(g[i][y]==val)
				return false;
		}
		if(i!=y){
			if(g[x][i]==val)
				return false;
		}
	}
	int a = (x/n) * n;
	int b = (y/n) * n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a+i!=x || b+j!=y){
				if(g[a+i][b+j] == val)
					return false;
			}
		}
	}
	return true;
}

bool solve(int x, int y){
	if(x==n*n){
		for(int i=0;i<n*n;i++){
			printf("%d", g[i][0]);
			for(int j=1;j<n*n;j++){
				printf(" %d", g[i][j]);
			}
			puts("");
		}
		return true;
	}
	bool temp;
	if(g[x][y]){
		if(y==n*n-1) 
			temp = solve(x+1, 0);
		else
			temp = solve(x, y+1);
		return temp;
	}
	for(int i=1;i<=n*n;i++){
		if(cek(x,y,i)){
			g[x][y]=i;
			if(y==n*n-1) 
				temp = solve(x+1, 0);
			else
				temp = solve(x, y+1);
			g[x][y]=0;
			if(temp){
				return true;
			}
		}
	}
	return false;
}

int main(){
	bool fir = true;
	while(scanf("%d", &n)==1&&n>0){
		for(i=0;i<n*n;i++){
			for(j=0;j<n*n;j++){
				scanf("%d", g[i]+j);
			}
		}
		for(i=0;i<n*n;i++){
			for(j=0;j<n*n;j++){
				if(g[i][j]){
					if(!cek(i,j,g[i][j])||g[i][j]>n*n){
						puts("NO SOLUTION");
						goto down;
					}
				}
			}
		}
		if(!fir)
			puts("");
		if(!solve(0,0))
			puts("NO SOLUTION");
		down :;
		fir = false;
	}
	return 0;
}
