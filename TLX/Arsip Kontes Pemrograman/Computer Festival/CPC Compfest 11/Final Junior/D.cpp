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
int mat[22][22];

int main(){
	scanf("%d %d", &n, &q);
    for(int i=0;i<q;++i){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        --a, --b;
        if(a > b) swap(a, b);
        mat[a][b] ^= c;
    }
    for(int x=0;x<n;++x){
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                if(!mat[i][j]) continue;
                for(int k=j+1;k<n;++j){
                    if(mat[i][j] == mat[j][k]) {
                        mat[i][k] ^= mat[i][j];
                        mat[i][j] = mat[j][k] = 0;
                    }
                }
            }
        }
    }

    int ans = 0;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            ans += mat[i][j] > 0;
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