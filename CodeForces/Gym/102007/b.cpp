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

const ll mod = 1e9+7;
const double PI = acos(-1);

void printArray(int *arr, int n){
    for(int i=0;i<n;++i)
        printf("%d ", arr[i]);
    puts("");
}

int n,i,j,k,t;
int a[400];
char s[100];
int m[] = {
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};
int sum[12];

int main(){
    memset(a, -1, sizeof a);
    sum[0] = 0;
    for(int i=1;i<=12;++i)
        sum[i] = sum[i-1] + m[i-1];
    scanf("%d", &n);
    for(int i=0;i<n;++i){
        int x, y;
        scanf("%s %d-%d", s, &x, &y);
        int tmp = sum[x-1] + y - 1;
        a[tmp] = 0;
    }
    for(int i=1;i<365;++i){
        if(a[i] != -1) continue;
        if(a[i-1] == -1) continue;
        a[i] = a[i-1] + 1;
    }
    for(int i=0;i<365;++i){
        if(a[i] != -1) continue;
        if(i == 0)
            a[i] = a[364] + 1;
        else
        {
            a[i] = a[i-1] + 1;
        }
    }
    // printArray(a, 31);
    // printArray(a + sum[9], 31);
    int idx = 0, st = sum[9] + 27;
    int ma = *max_element(a, a+365);
    for(int i=0;i<365;++i){
        if(a[(i + st) % 365] == ma){
            idx = (i + st) % 365;
            break;
        }
    }
    int m = upper_bound(sum, sum+13, idx) - sum;
    int d = idx - sum[m-1] + 1;
    // printf("%d %d %d %d\n", idx, m, d, ma);
    printf("%02d-%02d\n", m, d);
    return 0;
}