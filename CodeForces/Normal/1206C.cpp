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
int ans[400005];

int main(){
	scanf("%d", &n);
    if(n < 2){
        puts("YES");
        for(int i=1;i<=2*n;++i){
            printf("%d ", i);
        }
        puts("");
        return 0;
    }
    int a = 1, b = 2*n;
    for(int i=0;i<n;++i){
        if(i%2 == 0){
            ans[i] = a;
            ans[i+n] = a+1;
            a += 2;
        }
        else{
            ans[i] = b;
            ans[i+n] = b-1;
            b -= 2;
        }
    }
    for(int i=0;i<2*n;++i){
        ans[i+2*n] = ans[i];
    }
    ll sum = 0;
    set<ll> cans;
    for(int i=0;i<n;++i){
        sum += ans[i];
    }
    for(int i=0;i<2*n;++i){
        cans.insert(sum);
        sum -= ans[i];
        sum += ans[i+n];
    }
    if(cans.size() > 2){
        return puts("NO"), 0;
    }
    puts("YES");
    for(int i=0;i<2*n;++i){
        printf("%d ", ans[i]);
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