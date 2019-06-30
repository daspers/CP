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
int dist[51][51];

int main(){
	scanf("%d", &t);
    for(int cc=1;cc<=t;++cc){
        printf("Case #%d: ", cc);
        scanf("%d %d", &n, &m);
        for(int i=1;i<=n;++i){
            dist[i][i] = 0;
            for(int j=i+1;j<=n;++j){
                dist[i][j] = dist[j][i] = 5e8;
            }
        }
        vector<pair<pii, int>> ans;
        for(int i=0;i<m;++i){
            int a,b,c;
            scanf("%d %d %d", &a, &b, &c);
            ans.pb({{a,b},c});
            dist[a][b] = dist[b][a] = c;
        }
        bool bisa = true;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                for(int k=1;k<=n;++k){
                    dist[j][k] = min(dist[j][k], dist[j][i]+dist[i][k]);
                }
            }
        }
        for(const pair<pii, int> &x: ans){
            if(dist[x.fi.fi][x.fi.se]  != x.se){
                bisa = false;
                break;
            }
        }
        if(bisa){
            printf("%d\n", (int)ans.size());
            for(const pair<pii, int> &x: ans){
                printf("%d %d %d\n", x.fi.fi, x.fi.se, x.se);
            }
        }
        else{
            puts("Impossible");
        }
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