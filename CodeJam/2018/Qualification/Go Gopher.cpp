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

int n,t,j,i,k;
bool a[1001][1001];

bool cek(int x, int y){
	for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){
			if(a[x+i][y+j] == false)
				return false;
		}
	}
	return true;
}

int main(){
	cin>>t;
	for(int cc=1;t--;cc++){
		memset(a, false, sizeof a);
		cin>>n;
		int x=2, y=2;
		int c, d;
		cout<<x<<" "<<y<<"\n"<<flush;
		while(cin>>c>>d, c>0&&d>0){
			a[c][d] = true;
			if(cek(x, y)){
				x += 3;
			}
			cout<<x<<" "<<y<<"\n"<<flush;
		}
		if(c==-1 && d==-1)
			break;
	}
	return 0;
}