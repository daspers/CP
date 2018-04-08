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
int a,b,c,d, m;
string s[201];
int def[201][201];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};


int main(){
	scanf("%d", &t);
	for(int cc=1;t--;cc++){
		memset(def, -1, sizeof def);
		printf("Case #%d: ", cc);
		scanf("%d %d", &n, &m);
		for(i=0;i<n;i++){
			cin>>s[i];
		}
		scanf("%d %d", &a, &b);
		scanf("%d %d", &c, &d);
		priority_queue<pair<int, pair<int, int> > > q;
		def[a][b] = s[a][b] == '#';
		q.push({-def[a][b],{a,b}});
		while(!q.empty()){
			pair<int, pair<int, int> > temp = q.top();
			q.pop();
			for(i=0;i<4;i++){
				int xx = temp.se.fi+dx[i];
				int yy = temp.se.se+dy[i];
				if(xx>=0&&xx<n&&yy>=0&&yy<m){
					int tam  = s[xx][yy] == '#';
					if(def[xx][yy]==-1){
						def[xx][yy] = def[temp.se.fi][temp.se.se]+tam;
						q.push({-def[xx][yy], {xx,yy}});
					}
				}
			}
		}
		printf("%d\n", def[c][d]);
	}
	return 0;
}