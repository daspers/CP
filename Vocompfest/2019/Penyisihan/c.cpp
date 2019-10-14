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
int a[100005];
int ri2[100005];
int ri4[100005];

int main(){
	scanf("%d", &n);
    for(int i=1;i<=n;++i){
        scanf("%d", a+i);
    }
    ri2[n+1] = ri4[n+1] = n+1;
    ri2[n+2] = ri4[n+2] = n+2;
    for(int i=n;i>=1;--i){
        ri2[i] = ri2[i+1];
        ri4[i] = ri4[i+1];
        if(a[i] % 4 == 0){
            ri4[i] = i;
        }
        else if(a[i] % 2 == 0){
            ri2[i] = i;
        }
    }
    // printArray(ri2, n+2);
    // printArray(ri4, n+2);
    ll ans = 0;
    for(int i=1;i<=n;++i){
        int r2 = i;
        int r4 = i;
        r2 = ri2[i];
        r2 = min(ri2[r2+1], ri4[r2+1]);
        r4 = ri4[i];
        int r = min(r2, r4);
        // cerr<<i<<" "<<r<<" "<<r2<<" "<<r4<<endl;
        if(r > n) break;
        ans += n - r + 1;
    }
    printf("%lld\n", ans);
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