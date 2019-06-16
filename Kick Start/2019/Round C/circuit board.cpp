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
int a[303][303];
int ri[303][303];

int main(){
	scanf("%d", &t);
    for(int cc=1;cc<=t;++cc){
        printf("Case #%d: ", cc);
        scanf("%d %d %d", &n, &m, &k);
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                scanf("%d", a[i]+j);
            }
        }
        // cerr<<n<<" "<<m<<" "<<k<<endl;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                int mi = a[i][j], ma =a[i][j];
                int l = j;
                for(;l<m;++l){
                    ma = max(ma, a[i][l]);
                    mi = min(mi, a[i][l]);
                    if(ma-mi>k) break;
                }
                ri[i][j] = l-1;
            }
        }
        // cerr<<"preprocess aman"<<endl;
        int ans = 1;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                int mi = m-1;
                for(int k=i;k<n;++k){
                    mi = min(mi, ri[k][j]);
                    ans = max(ans, (k-i+1)*(mi-j+1));
                }
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