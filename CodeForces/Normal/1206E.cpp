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
int m[55][55];
int dx[] = {2, 1, 0};
int dy[] = {0, 1, 2};
int par[55*55];
int in;

int get_set(int v){
    if(v == par[v])
        return v;
    return par[v] = get_set(par[v]);
}

void union_set(int a, int b){
    a = get_set(a);
    b = get_set(b);
    if(a != b){
        par[b] = a;
    }
}

int switch_func(int val, int state){
    return state ? val : !val;
}

int switch_func2(int val, int state){
    return state ? val : !(val-2)+2;
}

int ask(int r1, int c1, int r2, int c2){
    int ans;
    cout<<"? "<<r1<<" "<<c1<<" "<<r2<<" "<<c2<<endl;
    cin>>ans;
    return ans;
}

void fill_matrix(pii start, int (*transformer)(int, int)){
    queue<pii> q;
    q.push(start);
    while(!q.empty()){
        pii tmp = q.front();
        q.pop();
        for(int i=0;i<3;++i){
            int xx = tmp.fi + dx[i];
            int yy = tmp.se + dy[i];
            if(m[xx][yy] != -1 || xx > n || yy > n) continue;
            int ans = ask(tmp.fi, tmp.se, xx, yy);
            m[xx][yy] = transformer(m[tmp.fi][tmp.se], ans);
            q.push({xx, yy});
        }
    }
}

int main(){
    cin>>n;
    memset(m, -1, sizeof m);
    m[1][1] = 1;
    m[n][n] = 0;
    fill_matrix({1,1}, switch_func);
    m[1][2] = 2;
    fill_matrix({1, 2}, switch_func2);
    int in = ask(2, 1, 3, 2);
    m[2][1] = switch_func2(m[3][2], in);
    fill_matrix({2, 1}, switch_func2);
    int cnt = 0;
    int x = 1;
    for(int i=2;i<=n;++i){
        for(int j=2;j<=n;++j){
            if(i+j < 5 || m[i][j] > 1 || m[i][j] < 0) continue;
            if(i > 2){
                // d d r
                bool bisa = false;
                bisa = bisa || ((m[i][j] == m[i-1][j-1]) == (m[i-2][j-1] == m[i][j-1]));
                bisa = bisa || ((m[i][j] == m[i-1][j-1]) == (m[i-2][j-1] == m[i-1][j]));
                bisa = bisa || ((m[i][j] == m[i-2][j]) == (m[i-2][j-1] == m[i-1][j]));
                if(bisa){
                    int ans = ask(i-2, j-1, i, j);
                    x = ans == (m[i-2][j-1] == 2) ? m[i][j] : !m[i][j];
                    cnt++;
                    break;
                }
            }
            if(j > 2){
                bool bisa = false;
                bisa = bisa || ((m[i][j] == m[i-1][j-1]) == (m[i-1][j-2] == m[i-1][j]));
                bisa = bisa || ((m[i][j] == m[i-1][j-1]) == (m[i-1][j-2] == m[i][j-1]));
                bisa = bisa || ((m[i][j] == m[i][j-2]) == (m[i-1][j-2] == m[i][j-1]));
                if(bisa){
                    int ans = ask(i-1, j-2, i, j);
                    x = ans == (m[i-1][j-2] == 2) ? m[i][j] : !m[i][j];
                    cnt++;
                    break;
                }
            }
        }
        if(cnt) break;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(m[i][j] == 2) {
                m[i][j] = x;
            }
            else if(m[i][j] == 3){
                m[i][j] = !x;
            }
        }
    }
    cout<<"!"<<endl;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cout<<m[i][j];
        }
        cout<<endl;
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