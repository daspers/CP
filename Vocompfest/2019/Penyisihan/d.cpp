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
int cnta[102];
int cntb[102];

int main(){
	scanf("%d", &t);
    for(int cc=1;cc<=t;++cc){
        printf("Case #%d: ", cc);
        memset(cnta, 0, sizeof cnta);
        memset(cntb, 0, sizeof cntb);
        scanf("%d", &n);
        for(int i=0;i<n;++i){
            int x;
            scanf("%d", &x);
            cnta[x]++;
        }
        for(int i=0;i<n;++i){
            int x;
            scanf("%d", &x);
            cntb[x]++;
        }
        int bisa = 0;
        for(int i=100;i>=1;--i){
            if(cnta[i] == 0) continue;
            if(n - cnta[i] < cntb[i]){
                // cout<<n<<" "<<i<<" "<<cnta[i]<<" "<<cntb[i]<<endl;
                bisa = 2;
                break;
            }
            n -= cnta[i];
        }
        if(bisa ==2){
            puts("EXIST");
        }
        else{
            for(int i=1;i<=100;++i){
                if(cnta[i] > 0 &&  cntb[i] > 0){
                    bisa = 1;
                    break;
                }
            }
            if(bisa){
                puts("MAY EXIST");
            }
            else{
                puts("NOT EXIST");
            }
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