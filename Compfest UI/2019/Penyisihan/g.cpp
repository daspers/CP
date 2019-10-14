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

int a[100002], b[100002];
int cnta[100002], cntb[100002];

int main(){
	scanf("%d %d", &n, &k);
    for(int i=0;i<n;++i){
        scanf("%d", a+i);
        cnta[a[i]]++;
    }
    for(int i=0;i<n;++i){
        scanf("%d", b+i);
        cntb[b[i]]++;
    }
    int ans = 0;
    for(int i=1;i<=100000;++i)
        ans += max(cnta[i] + cntb[i] - n, 0);
    puts(ans <= k ?"Ya":"Tidak");
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