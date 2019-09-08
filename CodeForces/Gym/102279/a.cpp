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
int a, b, c;
int da[100002], db[100002], dc[100002], f[100002];

int main(){
    memset(da, -1, sizeof da);
    memset(db, -1, sizeof db);
    memset(dc, -1, sizeof dc);
	scanf("%d %d %d %d", &n, &a, &b, &c);
    int na = 0, nb = 0, nc = 0;
    memset(f, -1, sizeof f);
    int m = n+1;
    da[0] = 0, db[0] = 0, dc[0] = 0;
    f[0] = 0;
    int ans = 0;
    for(i=1;i<=n;++i){
        na = (na + a) % m;
        nb = (nb + b) % m;
        nc = (nc + c) % m;
        ans++;
        if(da[na] == -1){
            da[na] = i;
            if(na > 0){
                if (f[na] == -1) f[na] = 1; 
                else if (f[na] != 1) break;
            }
        }
        ans++;
        if(db[nb] == -1){
            db[nb] = i;
            if(nb > 0){
                if (f[nb] == -1) f[nb] = 2; 
                else  if (f[nb] != 2) break;
            }
        }
        ans++;
        if(dc[nc] == -1){
            dc[nc] = i;
            if(nc > 0){
                if (f[nc] == -1) f[nc] = 3; 
                else  if (f[nc] != 3) break;
            }
        }
    }
    printf("%lld\n", i > n ? 3000000000LL : (ll)ans);
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