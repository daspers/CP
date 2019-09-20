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
char s[102][102];
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
char op[256];

int main(){
    op['W'] = 'B';
    op['B'] = 'W';
    memset(s, '.', sizeof s);
	scanf("%d", &n);
    for(int i=0;i<n;++i){
        s[i][n] = 0;
    }
    queue<pii> q;
    s[0][0] = 'W';
    q.push({0, 0 });
    while(!q.empty()){
        pii tmp = q.front();
        q.pop();
        for(int i=0;i<8;++i){
            int xx = tmp.fi + dx[i];
            int yy = tmp.se + dy[i];
            if(xx>=0 && xx<n && yy>=0 && yy<n){
                if(s[xx][yy] == '.'){
                    s[xx][yy] = op[s[tmp.fi][tmp.se]];
                    q.push({xx, yy});
                }
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(s[i][j] == '.'){
                s[i][j] = 'W';
            }
        }
    }
    for(int i=0;i<n;++i){
        printf("%s\n", s[i]);
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