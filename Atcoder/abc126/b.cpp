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
char s[102];

int val(const char *s){
    return (s[0] -'0')*10 + s[1] -'0';
}

bool inrange(int val){
    return val >= 1 && val <=12;
}

int main(){
    scanf("%s", s);
    int a = val(s);
    int b = val(s+2);
    if(inrange(a) && inrange(b)){
        puts("AMBIGUOUS");
    }
    else if(inrange(a)){
        puts("MMYY");
    }
    else if(inrange(b)){
        puts("YYMM");
    }
    else{
        puts("NA");
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