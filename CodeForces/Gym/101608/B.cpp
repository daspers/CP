#include <bits/stdc++.h>
using namespace std;

const int nmax = 500;

int tc;
int n;

int main()
{
	FILE *F;
	F = fopen("overcode.in", "r");
	fscanf(F, "%d", &tc);
	for(int tt = 1; tt <= tc; tt++) {
		fscanf(F, "%d", &n);
		int arr[nmax + 5];
		for(int i = 0; i < n; i++) {
			fscanf(F, "%d", arr+i);
		}

		sort(arr, arr+n);
		int ans = 0;
		int i = 0;
		if (n < 6) {
			cout << 0 << "\n";
			continue;
		}
		bool found = false;
		while(i < n && i+5 < n) {
			found = false;
			if (arr[i+5]-arr[i] <= 1000) {
				ans++;
				found = true;
			}
			if (found) {
				i += 6;
			} else {
				i++;
			}
		}
		cout << ans << "\n";
	}
}