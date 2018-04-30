#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	
	vector<vector<int>> x(m + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; i++) {
		int k;
		scanf("%d", &k);
		
		for (int j = 1; j <= m; j++) {
			x[j][i] = x[j][i - 1];
			
			if (j == k) {
				x[j][i] += 1;
			}
		}
	}
	
	vector<int> y(m + 1);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &y[i]);
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				if (x[k][j] - x[k][i - 1] != y[k]) {
					break;
				}
				
				if (k == m) {
					printf("YES\n");
					
					return 0;
				}
			}
		}
	}
	
	printf("NO\n");
}