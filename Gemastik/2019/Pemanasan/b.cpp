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
double a[1000002];

int main(){
    n = 0;
    for(int i=0;scanf("%lf", a+i) == 1;++i)++n;
    bool bisa = true;
    if(n == 2){
        bisa = a[0] == a[1];
    }
    else {
        sort(a, a+n);
        double sum = 0;
        for(int i=0;i<n-1;++i){
            sum += a[i];
        }
        if(sum < a[n-1]){
            bisa = false;
        }
    }
    puts(bisa ? "MUNGKIN" : "MUSTAHIL");
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