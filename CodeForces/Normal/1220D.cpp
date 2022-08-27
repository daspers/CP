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
ll a[200002];
bool deleted[200002];

int main(){
	scanf("%d", &n);
    for(int i=0;i<n;++i){
        scanf("%d", a+i);
    }
    sort(a, a+i);
    vector<int> ans, v;
    int cnto = 0;
    for(int i=0;i<n;++i){
        if(a[i] & 1){
            cnto++;
        }
        else {
            v.pb(a[i]);
        }
    }
    for(int x : v){
        
    }
    printf("%d\n", (int)ans.size());
    for(int x : ans){
        printf("%d ", a[x]);
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