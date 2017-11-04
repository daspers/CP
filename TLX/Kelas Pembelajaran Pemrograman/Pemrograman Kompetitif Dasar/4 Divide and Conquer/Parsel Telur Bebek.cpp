#include <bits/stdc++.h>

using namespace std;

const long N = 262144;

long long n, i, j, k, a[N+5], l,r,mid,h,mi = 1e10,c,b;

int main() {
    scanf("%lld %lld", &n, &k);
	for(i=0; i<n;i++){
		scanf("%lld", a+i);
		mi = min(mi, a[i]);
	}
	a[n] = 1e13;
	sort(a, a+n);
	l = mi;
	r = 1e12;
	mid = (l+r)>>1;
	for(h=i=0;a[i]<=mid;i++)
		h += mid/a[i];
	while(h!=k && l<r){
		if(h>k)
			r = mid-1;
		else
			l = mid+1;
		mid = (l+r)>>1;
		for(h=i=0;a[i]<=mid;i++)
			h += mid/a[i];
	}
	c=h==k;
	if(c){
		j = mid;
		l = mi;
		r = j;
		mid = (l+r)>>1;
		for(b=h=i=0;a[i]<=mid;i++){
			h += mid/a[i];
			b += (mid-1)/a[i];
		}
		while(!(b<k && h==k) && l<r){
			if(h<k)
				l = mid+1;
			else if(b==k)
				r = mid-1;
			mid = (l+r)>>1;
			for(b=h=i=0;a[i]<=mid;i++){
				h += mid/a[i];
				b += (mid-1)/a[i];
			}
		}
		c+= j-mid;
		l = j;
		r = 1e12;
		mid = (l+r)>>1;
		for(b=h=i=0;a[i]<=mid;i++){
			h += mid/a[i];
			b += (mid+1)/a[i];
		}
		while(!(b>k && h==k) && l<r){
			if(h>k)
				r = mid-1;
			else if(b==k)
				l = mid+1;
			mid = (l+r)>>1;
			for(b=h=i=0;a[i]<=mid+1;i++){
				h += mid/a[i];
				b += (mid+1)/a[i];
			}
		}
		c+= mid-j;
	}
	printf("%lld\n", c);
    return 0;
}
