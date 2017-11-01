#include <bits/stdc++.h>

using namespace std;

int n, i, j, k, c,x, b[1005],u[10005];

int main() {
    scanf("%d %d", &n, &k);
	memset(u, 0, sizeof(u));
	for(i=0;i<n;i++)
		scanf("%d", b+i);
	for(i=0;i<k;i++){
		scanf("%d", &x);
		u[x]++;
	}
	sort(b, b+n);
	for(c=i=0;i<n;i++){
		if(u[b[i]]){
			u[b[i]]--;
			c++;
		}
		else if(u[b[i]+1]){
			u[b[i]+1]--;
			c++;
		}
	}
	printf("%d\n", c);
    return 0;
}
