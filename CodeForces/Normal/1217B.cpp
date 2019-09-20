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
pair<int, pii> a[100];

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        for(int i=0;i<n;++i){
            scanf("%d %d", &a[i].se.fi, &a[i].se.se);
            a[i].fi = a[i].se.fi - a[i].se.se;
        }
        sort(a, a+n, greater<pair<int ,pii>>());
        int ans = -1;
        for(int i=0;i<n;++i){
            if(a[0].fi > 0){
                if(ans == -1){
                    ans = 1 + max(0, (k - a[i].se.fi + a[0].fi - 1) / a[0].fi);
                }
                else {
                    ans = min(ans, 1 + max(0, (k - a[i].se.fi + a[0].fi - 1) / a[0].fi));
                }
            }
            else if (a[i].se.fi >= k) {
                ans = 1;
                break;
            }
        }
        printf("%d\n", ans);
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