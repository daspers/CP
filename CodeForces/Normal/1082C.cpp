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
int sum[100002];
vector<int> v[100002];

int main(){
    memset(sum, 0, sizeof sum);
    scanf("%d %d", &n, &m);
    for(i=0;i<n;++i){
        int a, b;
        scanf("%d %d", &a, &b);
        v[a].pb(b);
    }
    for(i=1;i<=m;++i){
        sort(v[i].begin(), v[i].end(), greater<int>());
        int tot = 0;
        for(j=0;j<v[i].size();++j){
            tot+=v[i][j];
            if(tot < 0)
                break;
            sum[j+1] += tot;
        }
    }
    printf("%d\n", *max_element(sum+1, sum+n+1));
    return 0;
}