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
int m, b;
char a[3000];
char s[1002][1002];
bool vis[1002][1002];
bool vas[1002][1002];

int main(){
    memset(vis, 0, sizeof vis);
    memset(vas, 0, sizeof vas);
	scanf("%d %d", &n, &m);
    scanf("%s", a);
    b = strlen(a);
    for(int i=0;i<n;++i)
        scanf("%s", s[i]);
    queue<pii> q;
    vis[n-1][m-1] = true;
    q.push({n-1, m-1});
    while(!q.empty()){
        pii tmp = q.front();
        q.pop();
        if(tmp.fi > 0){
            if(!vis[tmp.fi-1][tmp.se] && s[tmp.fi-1][tmp.se]=='.'){
                vis[tmp.fi-1][tmp.se] = true;
                q.push({tmp.fi-1, tmp.se});
            }
        }
        if(tmp.se > 0){
            if(!vis[tmp.fi][tmp.se-1] && s[tmp.fi][tmp.se-1]=='.'){
                vis[tmp.fi][tmp.se-1] = true;
                q.push({tmp.fi, tmp.se-1});
            }
        }
    }
    vas[0][0] = true;
    q.push({0, 0});
    while(!q.empty()){
        pii tmp = q.front();
        q.pop();
        if(tmp.fi + 1 < n){
            if(!vas[tmp.fi+1][tmp.se] && s[tmp.fi+1][tmp.se]=='.'){
                vas[tmp.fi+1][tmp.se] = true;
                q.push({tmp.fi+1, tmp.se});
            }
        }
        if(tmp.se + 1 < m){
            if(!vas[tmp.fi][tmp.se+1] && s[tmp.fi][tmp.se+1]=='.'){
                vas[tmp.fi][tmp.se+1] = true;
                q.push({tmp.fi, tmp.se+1});
            }
        }
    }
    int x = 0, y = 0;
    // for(int i=0;i<b;++i){
    //     if(a[i]=='v'){
    //         if(y+1 < m && vis[x][y+1]){
    //             s[x][y+1] = 'x';
    //         }
    //         x++;
    //     }
    //     if(a[i] == '>'){
    //         if(x + 1 < n && vis[x+1][y]){
    //             s[x+1][y] = 'x';
    //         }
    //         y++;
    //     }
    // }
    if(n < m){
        for(int i=0;i<b;++i){
            if(a[i]=='v'){
                if(y+1 < m && vis[x][y+1]){
                    s[x][y+1] = 'x';
                }
                x++;
                if(y > 0 && vas[x][y-1]){
                    s[x][y-1] = 'x';
                }
            }
            else{
                y++;
            }
        }
    }
    else{
        for(int i=0;i<b;++i){
            if(a[i] == '>'){
                if(x + 1 < n && vis[x+1][y]){
                    s[x+1][y] = 'x';
                }
                y++;
                if(x > 0 && vas[x-1][y]){
                    s[x-1][y] = 'x';
                }
            }
            else{
                x++;
            }
        }
    }
    for(int i=0;i<n;++i){
        printf("%s\n", s[i]);
    }
    puts("");
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(s[i][j] == '.' && !(vis[i][j] && vas[i][j]))
                printf("#");
            else printf("%c", s[i][j]);
        }
        puts("");
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