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
int q;
int a[200002];
int cnt[200002];
pii b[200002];


int main(){
    memset(b, -1, sizeof b);
	scanf("%d %d", &n, &q);
    for(int i=0;i<n;++i){
        scanf("%d", a+i);
        cnt[a[i]]++;
        if(b[a[i]].fi == -1){
            b[a[i]] = {i,i};
        }
        else {
            b[a[i]].se = i;
        }
    }
    int lf = 0, sum = 0, ma = 0;
    int ans = 0;
    set<int> c;
    for(int i=0;i<n;++i){
        lf = max(lf, b[a[i]].se);
        c.insert(a[i]);
        if(lf == i){
            int ma = 0, sum = 0;
            for(int x : c){
                ma = max(ma, cnt[x]);
                sum += cnt[x];
            }
            ans += sum - ma;
            c.clear();
        }
    }
    printf("%d\n", ans);
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