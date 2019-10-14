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
int pmi, pma, qmi, qma;
const int limit = 20;
map<pii, pii> dp[limit+2];

pii solve(int it, int a, int b){
    if(!dp[it].count({a, b})){
        // cerr<<">> "<<it<<" "<<a<<" "<<b<<" "<<endl;
        pii ans = {0, it};
        if(a <= 0){
            ans = {-1, it};
        }
        else if(b <= 0){
            ans = {1, it};
        }
        else if(it < limit) {
            if(it & 1){
                ans = min(
                    solve(it + 1, a, b+m),
                    solve(it + 1, max(a-b, 0), b)
                );
            }
            else {
                ans = max(
                    solve(it + 1, a + n, b),
                    solve(it + 1, a, max(b-a, 0)),
                    [](const pii & a, const pii & b){
                        if(a.fi != b.fi){
                            return a.fi < b.fi;
                        }
                        return a.se > b.se;
                    }
                );
            }
        }
        dp[it][{a, b}] = ans;
    }
    return dp[it][{a, b}];
}

int main(){
	scanf("%d %d %d %d %d %d", &n, &m, &pmi, &pma, &qmi, &qma);
    ll ca = 0, cb = 0, cl=0;
    int mr = 0;
    for(int i=pmi;i<=pma;++i){
        for(int j=qmi;j<=qma;++j){
            pii res = solve(0, i, j);
            cerr<<"Round "<<i<<" "<<j<<": ";
            if(res.fi > 0){
                cerr<<"a win in "<<res.se<<endl;
                ++ca;
                mr = max(mr, res.se);
            }
            else if (res.fi < 0){
                cerr<<"b win in "<<res.se<<endl;
                ++cb;
                mr = max(mr, res.se);
            }
            else {
                ++cl;
                cerr<<endl;
            }
        }
    }
    cerr<<"result : "<<ca<<" "<<cb<<" "<<cl<<" in "<<mr<<endl;
    // ll ca = 0, cb = 0;
    if(n > m){
        for(int i=qmi;i<=qma;++i){
            cb += max(0, min(i-n, i/2) - pmi + 1);
        }
        for(int i=pmi;i<=pma;++i){
            ca += max(i - qmi+1, 0);
        }
    }
    else {

    }
    printf("%lld %lld\n", ca, cb);
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