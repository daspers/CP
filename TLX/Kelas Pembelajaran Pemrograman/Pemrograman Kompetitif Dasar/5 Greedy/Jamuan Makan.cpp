#include <bits/stdc++.h>

using namespace std;

#define se second
#define fi first

int n, x,y, i, j, k,l,c;
pair<int, int> a[100005];

int main() {
    scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d %d", &x, &y);
		a[i] = make_pair(x+y, x);
	}
	sort(a, a+n);
	for(l=c=i=0;i<n;i++){
		if(a[i].se >= l){
			c++;
			l = a[i].fi;
		}
	}
	printf("%d\n", c);
    return 0;
}
