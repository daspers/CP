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
bool isp[2000006];
int ans[2000006];
int num[2000006];

int main(){
    // clock_t tStart = clock();
    memset(isp, true, sizeof isp);
    for(i=1;i<=2000000;++i){
        ans[i] = 1;
        num[i] = 0;
    }
    for(int i=2;i<=1000000;++i){
        if(!isp[i]) continue;
        for(int j=2*i;j<=2000000;j+=i){
            int tmp = j;
            int cnt = 0;
            do{
                cnt ++;
                tmp /= i;
            }while(tmp % i == 0);
            ans[j] *= cnt+1;
            num[j] ++;
            isp[j] = false;
        }
    }
    // printf("Time taken: %.4fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("%d\n", ans[n] - num[n]);
    }
    return 0;
}