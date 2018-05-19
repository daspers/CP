#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

void solve(int n, int m, int &x, int &y) {
	int pem = n, bagi;
	int kud = m;
	if(n==1){
		x = 1;
		y = 1;
		switch(kud){
			case 0:
				break;
			case 1:
				y++;
				break;
			case 2:
				y++, x++;
				break;
			case 3:
				x++;
				break;
		}
		return;
	}
	bagi = pem/2;
	pem = bagi*bagi;
	kud = (m/pem) % 4;
	solve(n/2, m-kud * pem, x, y);
	switch(kud){
		case 0:
			swap(x, y);
			break;
		case 1:
			y += bagi;
			break;
		case 2:
			x += bagi;
			y += bagi;
			break;
		case 3:
			int temp = x;
			x = 2*bagi - y + 1;
			y = bagi - temp + 1;
			break;
	}
	// cout<<kud<<" "<<x<<" "<<y<<endl;
	return;
}

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int x=1;
	int y=1;
	solve(n, m-1, x, y);
	printf("%d %d\n", x, y);
	return 0;
};