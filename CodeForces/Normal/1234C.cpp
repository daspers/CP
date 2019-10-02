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
char a[2][200004];
bool vis[2][200004][4];

int main(){
	scanf("%d", &q);
    while(q--){
	    scanf("%d", &n);
        scanf("%s", a[0]+1);
        scanf("%s", a[1]+1);
        a[0][0] = a[1][0] = a[0][n+1] = a[1][n+1] = '0';
        memset(vis[0], 0, 4 * n + 8);
        memset(vis[1], 0, 4 * n + 8);
        queue<pair<pii, int>> q;
        q.push({{0, 1}, 0});
        vis[0][1][0] = true;
        vis[0][0][0] = true;
        // cerr<<(int)vis[1][n+1][0]<<" "<<(int)vis[1][n+1][1]<<" "<<(int)vis[1][n+1][2]<<" "<<(int)vis[1][n+1][3]<<endl;
        while(!q.empty()){
            pair<pii, int> now = q.front();
            q.pop();
            // cerr<<"goto "<<now.fi.fi<<" "<<now.fi.se<<" from "<<now.se<<endl;
            if(a[now.fi.fi][now.fi.se] >= '1' && a[now.fi.fi][now.fi.se] <= '2'){
                int xx = now.fi.fi;
                int yy = now.fi.se;
                int ne = now.se;
                if(now.se == 0){
                    yy++;
                }
                else if(now.se == 1){
                    xx++;
                }
                else if(now.se == 2){
                    yy--;
                }
                else {
                    xx--;
                }
                if(xx>=0 && xx<=1 && yy>=0 && yy<=n+1 && !vis[xx][yy][ne]){
                    vis[xx][yy][ne] = true;
                    q.push({{xx, yy}, ne});
                }
            }
            else if(a[now.fi.fi][now.fi.se] >= '3' && a[now.fi.fi][now.fi.se] <= '6') {
                int xx = now.fi.fi;
                int yy = now.fi.se;
                int ne = now.se;
                vector<pair<pii, int>> v;
                if(now.se == 0){
                    v.push_back({{xx-1, yy}, 3});
                    v.push_back({{xx+1, yy}, 1});
                }
                else if(now.se == 1){
                    v.push_back({{xx, yy-1}, 2});
                    v.push_back({{xx, yy+1}, 0});
                }
                else if(now.se == 2){
                    v.push_back({{xx-1, yy}, 3});
                    v.push_back({{xx+1, yy}, 1});
                }
                else {
                    v.push_back({{xx, yy-1}, 2});
                    v.push_back({{xx, yy+1}, 0});
                }
                for(pair<pii, int> x : v){
                    xx = x.fi.fi;
                    yy = x.fi.se;
                    ne = x.se;
                    if(xx>=0 && xx<=1 && yy>=0 && yy<=n+1 && !vis[xx][yy][ne]){
                        vis[xx][yy][ne] = true;
                        q.push({{xx, yy}, ne});
                    }
                }
            }
        }
        // cerr<<(int)vis[1][n+1][0]<<" "<<(int)vis[1][n+1][1]<<" "<<(int)vis[1][n+1][2]<<" "<<(int)vis[1][n+1][3]<<endl;
        puts(*max_element(vis[1][n+1], vis[1][n+1]+4)  ? "YES" : "NO");
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