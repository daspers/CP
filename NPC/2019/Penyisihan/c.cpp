#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-9
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void printArray(const int *arr, int n);
void printArray(const vector<int> &arr);

const ll mod = 1e9+7;
const double PI = acos(-1);

int n,i,j,k,t;
int m;
int a[10][100002];
char s[8];
int bit[10][100002];
int LOGN;

int bit_search(const int *bit, int v){
	int sum = 0;
	int pos = 0;
	for(int i=LOGN; i>=0; i--){
		if(pos + (1 << i) < m && sum + bit[pos + (1 << i)] < v)
		{
			sum += bit[pos + (1 << i)];
			pos += (1 << i);
		}
	}
	return pos + 1;
}

void update(int *bit, int idx, int val) {
	for(int i=idx;i<=m;i+=(i&-i)){
		bit[i] += val;
	}
}

int query(const int *bit, int idx) {
	int ans = 0;
	for(int i=idx;i>=1;i-=(i&-i)){
		ans += bit[i];
	}
	return ans;
}

int rangeQuery(const int *bit, int ql, int qr){
	return query(bit, qr) - query(bit, ql-1);
}

void print_bit(int *bit){
	for(int j=0;j<=m;++j){
		cerr<<query(bit, j)<<" ";
	}
	cerr<<endl;
}

int main(){
	scanf("%d %d", &n, &m);
	LOGN = ceil(log2(m));
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			scanf("%d", a[i]+j);
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			update(bit[i], j+1, a[i][j]);
		}
	}
	scanf("%d", &t);
	while(t--){
		scanf("%s", s);
		if(!strcmp(s, "ON")){
			int sum = 0;
			for(int i=0;i<n;++i){
				sum += query(bit[i], m);
			}
			printf("%d\n", sum);
		}
		else if(!strcmp(s, "OFF")){
			int sum = 0;
			for(int i=0;i<n;++i){
				sum += query(bit[i], m);
			}
			printf("%d\n", n*m - sum);
		}
		else if(!strcmp(s, "TOGGLE")){
			int r, idx;
			scanf("%d %d", &idx, &r);
			idx--;
			a[idx][r-1] = !a[idx][r-1];
			update(bit[idx], r, a[idx][r-1]);
			// print_bit(bit[idx]);
			puts("DONE");
		}
		else if(!strcmp(s, "COUNT")){
			int idx, ql, qr;
			scanf("%d %d %d", &idx, &ql, &qr);
			--idx;
			printf("%d\n", rangeQuery(bit[idx], ql, qr));
		}
		else if(!strcmp(s, "FIND")){
			int x;
			scanf("%d", &x);
			int ans = -1;
			int room = 0;
			int sum = 0;
			for(int i=0;i<n;++i){
				int curr = query(bit[i], m);
				if(curr + sum >= x){
					room = bit_search(bit[i], x - sum);
					ans = i+1;
					break;
				}
				sum += curr;
			}
			if(ans > 0){
				printf("%d %d\n", ans, room);
			}
			else {
				puts("-1");
			}
		}
	}
	return 0;
}

/* Template Function */
void printArray(const int * a, int n){
	for(int i=0;i<n;++i){
		printf("%d ", a[i]);
	}
	puts("");
}

void printArray(const vector<int> &arr){
	for(int x : arr){
		printf("%d ", x);
	}
	puts("");
}