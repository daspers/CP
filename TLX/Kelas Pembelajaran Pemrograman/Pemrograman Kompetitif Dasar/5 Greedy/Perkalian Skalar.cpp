#include <bits/stdc++.h>

using namespace std;

long n, i, j, k,v1[10005], v2[10005],c;

int main() {
    scanf("%ld", &n);
	for(i=0;i<n;i++)
		scanf("%ld", v1+i);
	for(i=0;i<n;i++)
		scanf("%ld", v2+i);
	sort(v1, v1+n);
	sort(v2, v2+n, greater<int>());
	for(c=i=0;i<n;i++){
		c+=v1[i]*v2[i];
	}
	printf("%ld\n", c);
    return 0;
}
