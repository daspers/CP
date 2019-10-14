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
int a[31][31];
int b[31][31];
int dpma[31][31];
int dpmi[31][31];
char ans[100];
map<int,ll> cnt[31][31];
int m;

int main(){
    ll k;
	scanf("%d %d %lld", &n, &m, &k);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            scanf("%d", b[i]+j);
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            a[i][j] = b[n-i-1][m-j-1];
        }
    }
    // dpma[0][0] = dpma[0][0] = a[0][0];
    cnt[0][0][a[0][0]] = 1;
    int sums = a[0][0];
    for(int i=1;i<n;++i){
        // dpma[i][0] = dpmi[i][0] = dpmi[i-1][0] + a[i][0];
        sums += a[i][0];
        cnt[i][0][sums] = 1;
    }
    sums = a[0][0];
    for(int i=1;i<m;++i){
        sums += a[0][i];
        cnt[0][i][sums] = 1;
    }
    for(int i=1;i<n;++i){
        for(int j=1;j<m;++j){
            // dpma[i][j] = max(dpma[i-1][j], dpma[i][j-1]) + a[i][j];
            // dpmi[i][j] = min(dpmi[i-1][j], dpmi[i][j-1]) + a[i][j];
            for(const pair<int, ll>& x : cnt[i][j-1]){
                cnt[i][j][x.fi+a[i][j]] += x.se;
            }
            for(const pair<int, ll>& x : cnt[i-1][j]){
                cnt[i][j][x.fi+a[i][j]] += x.se;
            }
        }
    }
    vector<pair<int, ll>> v;
    for(const pair<int, ll> x : cnt[n-1][m-1]){
        // cerr<<x.fi<<" "<<x.se<<endl;
        v.pb(x);
    }
    sort(v.begin(), v.end(), greater<pair<int, ll>>());
    int cost = 0;
    --k;
    for(const pair<int, ll>& x : v){
        if(k < x.se){
            cost = x.fi;
            break;
        }
        k -= x.se;
    }
    // debug(cost);
    // debug(k);
    queue<pii> q;
    q.push({n-1, m-1});
    ans[n+m-2] = 0;
    int curr = n+m-3;
    while(!q.empty()){
        pii tmp = q.front();
        // cerr<<"at ("<<tmp.fi<<" "<<tmp.se<<") cost="<<k<<endl;
        cost -= a[tmp.fi][tmp.se];
        q.pop();
        if(tmp.fi > 0 && tmp.se > 0) {
            // cerr<<"  "<<k<<" "<<cnt[tmp.fi-1][tmp.se][cost]<<" "<<cnt[tmp.fi-1][tmp.se][cost]<<endl;
            if(k>=cnt[tmp.fi-1][tmp.se][cost]){
                k -= cnt[tmp.fi-1][tmp.se][cost];
                ans[curr--] = 'R';
                q.push({tmp.fi, tmp.se-1});
            }
            else {
                ans[curr--] = 'D';
                q.push({tmp.fi-1, tmp.se});
            }
        }
        else if(tmp.fi>0) {
            ans[curr--] = 'D';
            q.push({tmp.fi-1, tmp.se});
        }
        else if(tmp.se > 0) {
            ans[curr--] = 'R';
            q.push({tmp.fi, tmp.se-1});
        }
    }
    reverse(ans, ans + n+m-2);
    printf("%s\n", ans);
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