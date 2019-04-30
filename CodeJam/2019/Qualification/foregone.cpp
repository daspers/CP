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
char a[200], b[200];

int main(){
	scanf("%d", &t);
    for(int cc=1;cc<=t;++cc){
        printf("Case #%d: ", cc);
        scanf("%s", a);
        n = strlen(a);
        reverse(a, a+n);
        memset(b, 0, sizeof b);
        bool gg = false;
        for(int i=n-1;i>=0;--i){
            if(a[i] =='4'){
                a[i] = '3';
                b[i] = '1';
                gg = true;
            }
            else if(gg){
                b[i] = '0';
            }
        }
        int m = strlen(b);
        reverse(b, b+m);
        reverse(a, a+n);
        printf("%s %s\n", a, b);
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