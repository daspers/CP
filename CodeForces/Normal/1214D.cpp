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
char ** a;
bool **vis, **vist, **visb;
int **tin, **low, **ch;
int timer;
bool has_cutpoint = false;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void dfs(int x, int y, int px, int py) {
    // cerr<<"masuk "<<x<<" "<<y<<endl;
    vis[x][y] = true;
    tin[x][y] = low[x][y] = timer++;
    ch[x][y] = 0;
    for(int i=0;i<4;++i){
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx>=0 && xx<n && yy>=0 && yy<m){
            if(xx == px && yy == py || a[xx][yy] == '#') continue;
            if (vis[xx][yy]) {
                low[x][y] = min(low[x][y], tin[xx][yy]);
            } else {
                // cerr<<"   ke "<<xx<<" "<<yy<<endl;
                dfs(xx, yy, x, y);
                if (low[xx][yy] >= tin[x][y] && !(px == x && py == y)){
                    // cerr<<x<<" "<<y<<endl;
                    has_cutpoint |= !(!x && !y) && !(x == n-1 && y == m-1);
                }
                low[x][y] = min(low[x][y], low[xx][yy]);
                ++ch[x][y];
            }
        }
    }
    if(!(px == x && py == y) && ch[x][y] > 1)
        // cerr<<x<<" "<<y<<endl;
        has_cutpoint |= !(!x && !y) && !(x == n-1 && y == m-1);
    // cerr<<"keluar "<<x<<" "<<y<<endl;
}

void dfst(int x, int y) {
    vist[x][y] = true;
    for(int i=0;i<2;++i){
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx>=0 && xx<n && yy>=0 && yy<m){
            if(a[xx][yy] == '#' || vist[xx][yy]) continue;
            dfst(xx, yy);
        }
    }
}

void dfsb(int x, int y) {
    visb[x][y] = true;
    for(int i=2;i<4;++i){
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx>=0 && xx<n && yy>=0 && yy<m){
            if(a[xx][yy] == '#' || visb[xx][yy]) continue;
            dfsb(xx, yy);
        }
    }
}

int main(){
	scanf("%d %d", &n, &m);
    a = new char *[n+1];
    vis = new bool *[n+1];
    vist = new bool *[n+1];
    visb = new bool *[n+1];
    tin = new int *[n+1];
    low = new int *[n+1];
    ch = new int *[n+1];
    for(int i=0;i<n;++i){
        a[i] = new char[m+2];
        vis[i] = new bool[m+2];
        vist[i] = new bool[m+2];
        visb[i] = new bool[m+2];
        tin[i] = new int[m+2];
        low[i] = new int [m+2];
        ch[i] = new int [m+2];
        scanf("%s", a[i]);
        for(int j=0;j<m;++j){
            vis[i][j] = false;
            vist[i][j] = false;
            visb[i][j] = false;
        }
    }
    int ans = 2;
    int cnt = 0;
    if(n > 1 && m > 1){
        cnt += a[1][0] == '#';
        cnt += a[0][1] == '#';
        ans = min(ans, 2-cnt);
        cnt = 0;
        cnt += a[n-1][m-2] == '#';
        cnt += a[n-2][m-1] == '#';
        ans = min(ans, 2-cnt);
        has_cutpoint = false;
        // dfs(0, 0, 0, 0);
        dfst(0, 0);
        dfsb(n-1, m-1);
        for(int i=1;i<n+m-2;++i){
            int cnt = 0;
            for(int j=0;j<n && j<=i;++j){
                if(i-j >= m) continue;
                cnt += visb[j][i-j] && vist[j][i-j];
            }
            ans = min(ans, cnt);
        }
        // if(!vis[n-1][m-1]){
        //     ans = 0;
        // }
        // else if(has_cutpoint) {
        //     ans = min(ans, 1);
        // }
    }
    else if(n == 1){
        ans = 1;
        for(int i=0;i<m;++i){
            if(a[0][i] == '#'){
                ans = 0 ;
                break;
            }
        }
    }
    else if(m == 1){
        ans = 1;
        for(int i=0;i<n;++i){
            if(a[i][0] == '#'){
                ans = 0 ;
                break;
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