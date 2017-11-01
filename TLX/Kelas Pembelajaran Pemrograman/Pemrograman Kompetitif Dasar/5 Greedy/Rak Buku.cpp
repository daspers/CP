#include <bits/stdc++.h>

using namespace std;

long n, h[20005], i, j, k;

int main() {
    scanf("%ld %ld", &n, &k);
    for(i=0;i<n;i++){
		scanf("%ld", h+i);
	}
	sort(h, h+n, greater<long>());
	i=0;
	while(k>0){
		k -= h[i++];
	}
	printf("%ld\n", i);
    return 0;
}
