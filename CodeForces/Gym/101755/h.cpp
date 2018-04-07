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

struct loc
{
	loc(int a, int b, int c){
		x= a;
		y = b;
		d = c;
	}
	int x;
	int y;
	int d;
};

int n,t,j,i,k;
int **mip;
int m,d;
int a, b;
int f, g;
string *s;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

void print(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<mip[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	scanf("%d %d %d", &n, &m, &d);
	mip = new int*[n+1];
	s = new string[n+1];
	for(i=0;i<n;i++){
		mip[i] = new int[m+1];
		for(j=0;j<m;j++){
			mip[i][j] = -1;
		}
		cin>>s[i];
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(s[i][j] == 'M'){
				queue<pair<int, int> > q;
				mip[i][j] = -2;
				q.push({i,j});
				while(!q.empty()){
					pair<int, int> temp = q.front();
					q.pop();
					if(abs(temp.fi-i)+abs(temp.se-j) == d)
						break;
					for(k=0;k<4;k++){
						int xx = temp.fi+dx[k];
						int yy = temp.se+dy[k];
						if(xx>=0&&xx<n&&yy>=0&&yy<m){
							if(mip[xx][yy]==-1){
								mip[xx][yy] = mip[temp.fi][temp.se]-1;
								q.push({xx, yy});
							}
							else if(mip[xx][yy]<mip[temp.fi][temp.se]-1){
								mip[xx][yy] = mip[temp.fi][temp.se]-1;
								q.push({xx,yy});
							}
						}
					}
				}
			}
			else if(s[i][j] == 'S'){
				a = i;
				b = j;
			}
			else if(s[i][j] == 'F'){
				f=i;
				g=j;
			}
		}
	}
	//print();
	if(mip[a][b]<=-2 || mip[f][g]<=-2){
		puts("-1");
		return 0;
	}
	queue<pair<int, int>> q;
	mip[a][b] = 0;
	q.push({a, b});
	while(!q.empty()){
		pair<int, int> temp = q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int xx = temp.fi + dx[i];
			int yy = temp.se + dy[i];
			if(xx>=0&&xx<n && yy>=0&&yy<m){
				if(mip[xx][yy] == -1){
					mip[xx][yy] = mip[temp.fi][temp.se]+1;
					q.push({xx,yy});
				}
			}
		}
	}
	//print();
	printf("%d\n", mip[f][g]);
	for(i=0;i<n;i++)
		delete[] mip[i];
	delete[] mip;
	delete[] s;
	return 0;
}