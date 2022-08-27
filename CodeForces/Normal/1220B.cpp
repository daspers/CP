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
int a[1002][1002];
ll ans[1002];

int main(){
	scanf("%d", &n);
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            scanf("%d", a[i]+j);
        }
    }
    for(int i=0;i<n;++i){
        int curr = 0;
        for(int j=0;j<n;++j){
            curr = __gcd(curr, a[i][j]);
        }
        ans[i] = curr;
    }
    for(int i=0;i<n;++i){
        ll gcd = 0;
        for(int j=0;j<n;++j){
            if(i != j){
                gcd = __gcd(gcd, ans[i]*ans[j] / a[i][j]);
            }
        }
        ans[i] /= gcd;
        for(int j=0;j<n;++j){
            if(i != j){
                ans[j] /= ans[i]*ans[j] / a[i][j];
            }
        }
    }
    for(int i=0;i<n;++i){
        printf("%lld ", ans[i]);
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