#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[2005];
int b[2005];
int dp[2005][5];
int mar[2005][2005];

void printDp(int j) {
for (int i = 0; i < n; i++) {
printf("%d ", dp[i][j]);
}
printf("\n");
}

int main() {
scanf("%d%d", &n, &m);
for (int i = 0; i < n; i++) {
scanf("%d", &a[i]);
}
for (int i = 0; i < m; i++) {
scanf("%d", &b[i]);
}

for (int i = 0; i < n; i++) {
for (int j = i; j < n; j++) {
mar[i][j] = i == j ? a[i] : max(a[j], mar[i][j - 1]);
}
}

// b[0] dihandle di sini
for (int i = 0; i < n; i++) {
dp[i][0] = mar[0][i] == b[0] ? 1 : 0;
}
printDp(0);

// dp[i] adalah banyaknya kemungkinan, kalau array berhenti di i.
for (int j = 1; j < m; j++) {
int phase = 0;
int last_occ = -1;
for (int i = 0; i < n; i++) {
if (phase == 0) {
// phase 0 : belom nemu array dengan nilai = b[j]
dp[i][j % 2] = 0;
if (a[i] == b[j]) {
for (int k = 0; k < i; k++) {
if (mar[k + 1][i] == b[j]) {
dp[i][j % 2] += dp[k][1 - (j % 2)];
}
}
phase = 1;
last_occ = i;
}
} else if (phase == 1) {
if (a[i] < b[j]) {
dp[i][j % 2] = dp[i - 1][j % 2];
} else if (a[i] == b[j]) {
dp[i][j % 2] = dp[i - 1][j % 2];
for (int k = last_occ + 1; k <= i; k++) {
if (mar[k][i] == b[j]) { // actually, this is always true
dp[i][j % 2] += dp[k][1 - (j % 2)];
}
}
} else {
phase = 2;
dp[i][j % 2] = 0;
}
} else {
dp[i][j % 2] = 0;
}
}
printDp(j % 2);
}

printf("%d\n", dp[n-1][(m - 1) % 2]);
}