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
int m;
char s[500005];
int col[50005], row[50005];

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        for(int i=0;i<n;++i)
            scanf("%s", s+(i*(m+2)));
        for(int i=0;i<n;++i){
            row[i] = 0;
            for(int j=0;j<m;++j){
                row[i] += s[i*(m+2) + j] == '.';
            }
        }
        for(int i=0;i<m;++i){
            col[i] = 0;
            for(int j=0;j<n;++j){
                col[i] += s[j*(m+2) + i] == '.';
            }
        }
        int ans = m + n - 1;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                ans = min(ans, row[i] + col[j] - (s[i*(m+2)+j]=='.'));
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