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
char s[102], r[102], u[102];

bool compares(const char *a, const char *b, int n){
    for(int i=0;i<n;++i){
        if(a[i] < b[i]) return true;
        else if(a[i] > b[i]) return false;
    }
    return false;
}

int main(){
	scanf("%s", s);
    n = strlen(s);
    memcpy(r, s, n+1);
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            if((i == 0 && s[j] == '0') || s[i] <= s[j]) continue;
            memcpy(u, s, n+1);
            swap(u[i], u[j]);
            if(!compares(r, s, n) && !compares(s, r, n)){
                memcpy(r, u, n+1);
            }
            else if(compares(r, u, n)) {
                memcpy(r, u, n+1);
            }
        }
    }
    if(!compares(r, s, n) && !compares(s, r, n)){
        puts("-1");
    }
    else printf("%s\n", r);
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