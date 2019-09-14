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
char s[200];
pii a[102];
int main(){
	scanf("%d", &n);
    scanf("%s", s);
    for(int i=0;i<n;++i){
        scanf("%d %d", &a[i].fi, &a[i].se);
    }
    int ans = 0;
    for(int i=0;i<=800000;++i){
        int cnt = 0;
        for(int j=0;j<n;++j){
            if(i < a[j].se){
                cnt += s[j] - '0';
            }
            else {
                int tmp = (i - a[j].se) / a[j].fi + 1;
                if(tmp & 1){
                    cnt += '1' - s[j];
                }
                else {
                    cnt += s[j] - '0';
                }
            }
        }
        ans = max(ans, cnt);
    }
    // for(int i=0;i<n;++i){
    //     for(int j=0;j<=50;++j){
    //         bool switched = false;
    //         if(j >= a[i].se){
    //             int tmp = (j - a[i].se) / a[i].fi + 1;
    //             if(tmp & 1){
    //                 switched = true;
    //             }
    //         }
    //         printf("%c", switched ? ((s[i] - '0')^1) + '0': s[i]);
    //     }
    //     puts("");
    // }
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