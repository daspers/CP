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

int n,i,j,k,t;
int m;
int day[103][103];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
queue<pii> q;

int main(){
    memset(day, -1, sizeof(day));
    scanf("%d %d %d", &n, &m, &t);
    while(t--){
        int a,b;
        scanf("%d %d", &a, &b);
        q.push({--a, --b});
        day[a][b] = 1;
    }
    while(!q.empty()){
        pii tmp = q.front();
        q.pop();
        for(i=0;i<4;++i){
            int x = tmp.fi+dx[i];
            int y = tmp.se+dy[i];
            
            if(x>=0&&x<n&&y>=0&&y<m&&day[x][y]==-1){
                day[x][y] = day[tmp.fi][tmp.se] + 1;
                q.push({x, y});
            }
        }
    }
    int ma = 0;
    for(i=0;i<n;++i)
        for(j=0;j<m;++j)
            ma = max(ma, day[i][j]);
    printf("%d\n", ma);
    return 0;
}