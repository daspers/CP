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
int b,s;
int a[100002];
pii p[100002];
int c[100002];
ll sum[100002];

int main(){
	scanf("%d %d", &s, &b);
    int ma = 0;
    for(int i=0;i<s;++i){
        scanf("%d", a+i);
        ma = max(ma, a[i]);
    }
    for(int i=0;i<b;++i){
        scanf("%d %d", &p[i].fi, &p[i].se);
    }
    sort(p, p+b);
    for(int i=0;i<b;++i){
        c[i] = p[i].fi;
        sum[i] = p[i].se + (i ? sum[i-1] : 0);
    }
    for(int i=0;i<s;++i){
        ll ans = 0;
        int idx = upper_bound(c, c+b, a[i]) - c  - 1;
        if(idx >= 0){
            ans = sum[idx];
        }
        printf("%lld ", ans);
    }
    puts("");
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