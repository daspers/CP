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
char **s;
int **a;
int **b;

int rsum(int l, int r, int x){
    if(r>=0 && x>=0) {
        if(l>=0){
            return a[r][x] - a[l][x];
        }
        return a[r][x];
    }
    return 0;
}

int solve(int r, int c){
    int ma = 0;
    for(int i=r-1;i<n;++i){
        int now = 0;
        for(int j=0;j<c-1;++j){
            now += rsum(i-r, i, j);
        }
        for(int j=c-1;j<m;++j){
            now += rsum(i-r, i, j);
            ma = max(ma, now);
            now -= rsum(i-r, i, j-c+1);
        }
    }
    return ma;
}

int main(){
	scanf("%d %d", &n, &m);
    s = new char*[n+1];
    a = new int*[n+1];
    for(int i=0;i<n;++i){
        s[i] = new char[m+3];
        a[i] = new int[m+3];
        scanf("%s", s[i]);
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            a[i][j] = i?a[i-1][j] : 0;
            a[i][j] += s[i][j]-'0';
        }
    }
    int cnt = 0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cnt+=s[i][j]-'0';
        }
    }
    int ans = -1;
    for(int i=1;i<=sqrt(cnt);++i){
        if(cnt % i == 0){
            int r = i, c = cnt/i;
            int curr = 0;
            if(r <= n && c<=m){
                curr = solve(r, c);
                if(ans == -1) ans = cnt - curr;
                else ans = min(ans, cnt - curr);
            }
            if(r!=c && c <= n && r<=m){
                curr = solve(c, r);
                if(ans == -1) ans = cnt - curr;
                else ans = min(ans, cnt - curr);
            }
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