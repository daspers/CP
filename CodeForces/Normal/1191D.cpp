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
int a[100002];

int main(){
	scanf("%d", &n);
    for(int i=0;i<n;++i){
        scanf("%d", a+i);
    }
    sort(a, a+n);
    int cnt = 0;
    for(int i=1;i<n;++i){
        if(a[i] == a[i-1] && a[i] == 0) return puts("cslnb"), 0;
        cnt += a[i] == a[i-1];
    }
    if(cnt > 1) {
        return puts("cslnb"), 0;
    }
    for(int i=2;i<n;++i){
        if(a[i] == a[i-1] && a[i-1] == 1 + a[i-2])
            return puts("cslnb"), 0;
    }
    ll sum = 0;
    for(int i=0;i<n;++i){
        sum += a[i] - i;
    }
    if(sum & 1){
        puts("sjfnb");
    }
    else{
        puts("cslnb");
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