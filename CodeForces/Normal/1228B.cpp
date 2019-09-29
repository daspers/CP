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
int a[1002][1002];
int r[1002], c[1002];

int powmod(int a, int b){
    int res = 1;
    for(;b;b>>=1){
        if(b&1){
            res = 1LL*a*res % mod;
        }
        a = 1LL*a*a%mod;
    }
    return res;
}

int main(){
	scanf("%d %d", &n, &m);
    for(int i=0;i<n;++i){
        scanf("%d", r+i);
        for(int j=0;j<r[i];++j){
            if(a[i][j] && a[i][j] != 2){
                return puts("0"), 0;
            }
            a[i][j] = 2;
        }
        if(a[i][r[i]] && a[i][r[i]] != 1){
            return puts("0"), 0;
        }
        a[i][r[i]] = 1;
    }
    for(int i=0;i<m;++i){
        scanf("%d", r+i);
        for(int j=0;j<r[i];++j){
            if(a[j][i] && a[j][i] != 2){
                return puts("0"), 0;
            }
            a[j][i] = 2;
        }
        if(a[r[i]][i] && a[r[i]][i] != 1){
            return puts("0"), 0;
        }
        a[r[i]][i] = 1;
    }
    int cnt = 0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(a[i][j] == 0){
                cnt++;
            }
        }
    }
    printf("%d\n", powmod(2, cnt));
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