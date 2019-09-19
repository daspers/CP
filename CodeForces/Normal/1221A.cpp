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
ll a[10002];

int main(){
	scanf("%d", &t);
    while(t--){
	    scanf("%d", &n);
        multiset<ll> b;
        for(int i=0;i<n;++i){
            scanf("%lld", a+i);
            b.insert(a[i]);
        }
        bool bisa = false;
        while(b.size() > 1){
            ll x = *b.begin();
            b.erase(b.begin());
            if(x == 2048) bisa = true;
            if(x == *b.begin()){
                b.erase(b.begin());
                b.insert(2*x);
            }
        }
        bisa |= *b.begin() == 2048;
        puts(bisa?"YES":"NO");
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