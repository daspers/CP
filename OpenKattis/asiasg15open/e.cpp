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

int n,i,j,k,t;
int a[30], b;

int main(){
	int time = 0;
	int totpin = 0;
	int ans = 0;
	scanf("%d %d", &n, &b);
	priority_queue<int> pq;
	for(i=0;i<n;++i){
		scanf("%d", a+i);
		if(i==b){
			time += a[i];
			if(time <= 300)
				ans = 1, totpin = time;
		}
		else
			pq.push(-a[i]);
	}
	while(!pq.empty()){
		int tmp = -pq.top();
		pq.pop();
		if(tmp + time > 300)
			break;
		ans++;
		totpin += time + tmp;
		time += tmp;
	}
	printf("%d %d\n", ans, totpin);
	return 0;
};