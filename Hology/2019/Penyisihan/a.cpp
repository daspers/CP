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

void printArray(const bool *arr, int n);
void printArray(const vector<int> &arr);

const ll mod = 1e9+7;
const double PI = acos(-1);

int n,i,j,k,t;
int m, a, b;
int x,y;
char s[205][205];
bool vis[205][205];
set<pii> cek[205][205];

int main(){
	scanf("%d %d", &n, &m);
	scanf("%d %d", &x, &y);
	scanf("%d %d", &a, &b);
    for(int i=0;i<n;++i){
        scanf("%s", s[i]);
    }
    --x; --y;
    if(a >= m && b >= m){
        int cnt = 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j)
                cnt+= s[i][j] == '.';
        }
        printf("%d\n", cnt);
        return 0;
    }
    a = min(a, 2*m);
    b = min(b, 2*m);
    queue<pair<pii, pii> > q;
    q.push({{x, y}, {a, b}});
    while(!q.empty()){
        pair<pii, pii> tmp = q.front();
        q.pop();
        vis[tmp.fi.fi][tmp.fi.se] = true;
        int xx, yy;
        pii z = tmp.se;
        xx = tmp.fi.fi + 1;
        yy = tmp.fi.se;
        if(xx < n && s[xx][yy] == '.' && !cek[xx][yy].count(z)){
            cek[xx][yy].insert(z);
            q.push({{xx, yy}, z});
        }
        z = tmp.se;
        xx = tmp.fi.fi - 1;
        yy = tmp.fi.se;
        if(xx >= 0 && s[xx][yy] == '.' && !cek[xx][yy].count(z)){
            cek[xx][yy].insert(z);
            q.push({{xx, yy}, z});
        }
        z = tmp.se;
        xx = tmp.fi.fi;
        yy = tmp.fi.se - 1;
        z.fi -= 1;
        if(yy >= 0 && z.fi >= 0 && s[xx][yy] == '.' && !cek[xx][yy].count(z)){
            cek[xx][yy].insert(z);
            q.push({{xx, yy}, z});
        }
        z = tmp.se;
        xx = tmp.fi.fi;
        yy = tmp.fi.se + 1;
        z.se -= 1;
        if(yy < m && z.se >= 0 && s[xx][yy] == '.' && !cek[xx][yy].count(z)){
            cek[xx][yy].insert(z);
            q.push({{xx, yy}, z});
        }
    }
    int cnt = 0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j)
            cnt+= vis[i][j];
        // printArray(vis[i], m);
    }
    printf("%d\n", cnt);
	return 0;
}

/* Template Function */
void printArray(const bool * a, int n){
	for(int i=0;i<n;++i){
		printf("%d ", (int)a[i]);
	}
	puts("");
}

void printArray(const vector<int> &arr){
	for(int x : arr){
		printf("%d ", x);
	}
	puts("");
}