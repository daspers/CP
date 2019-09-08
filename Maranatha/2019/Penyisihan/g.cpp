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
int c, r;
pii b[102];
pll a[2002];
int cnt[1002];
set<int> adj[1002];

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &n, &c, &r);
        for(int i=0;i<r;++i){
            scanf("%d %d", &b[i].fi, &b[i].se);
            --b[i].fi;
            --b[i].se;
            adj[b[i].fi].insert(b[i].se);
            adj[b[i].se].insert(b[i].fi);
        }
        for(int i=0;i<n;++i){
            scanf("%lld %lld", &a[i].fi, &a[i].se);
            --a[i].fi;
            a[i+n] = a[i];
        }

        ll best_sum = 0;
        int best_cnt = 0;
        int best_diff = 0;

        memset(cnt, 0, n * sizeof(int));
        deque<pll> dq;
        ll sum = 0;
        int diff = 0;
        j=0;
        for(int i=0;i<2*n;++i){
            for(int x : adj[a[i].fi]) {
                while(cnt[x]){
                    sum -= dq.front().se;
                    if(--cnt[dq.front().fi] == 0) diff--;
                    dq.pop_front();
                }
            }
            while(dq.size() >= n) {
                sum -= dq.front().se;
                if(--cnt[dq.front().fi] == 0) diff--;
                dq.pop_front();
            }
            dq.push_back(a[i]);
            sum += a[i].se;
            if(++cnt[a[i].fi] == 1){
                diff++;
            }
            if(diff > best_diff){
                best_diff = diff;
                best_sum = sum;
                best_cnt = dq.size();
            }
            else if(diff == best_diff && sum > best_sum) {
                best_sum = sum;
                best_cnt = dq.size();
            }
        }

        printf("%lld %d\n", best_sum/best_cnt, best_diff);

        for(int i=0;i<c;++i){
            adj[i].clear();
        }
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