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
char s[1000002];

int main(){
    int x, y;
	scanf("%d %d", &x, &y);
    scanf("%s", s);
    n = strlen(s);
    reverse(s, s+n);
    for(int i=0;i<n;++i){
        if(s[i] == 'u'){
            --y;
        }
        else if(s[i] == 's'){
            ++y;
        }
        else if(s[i] == 'b'){
            ++x;
        }
        else {
            --x;
        }
    }
    printf("%d %d\n", x, y);
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