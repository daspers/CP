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
// int a[7002], b[7002];
pair<ll, int> a[7002];
map<ll, pair<int, ll>> m;

int main(){
	scanf("%d", &n);
    for(int i=0;i<n;++i){
        scanf("%lld", &a[i].fi);
    }
    for(int i=0;i<n;++i){
        scanf("%d", &a[i].se);
    }
    // sort(a, a+n);
    ll ans = 0;
    int cnt = 0;
    for(int i=0;i<n;++i){
        m[a[i].fi] = {m[a[i].fi].fi+1, m[a[i].fi].se + a[i].se};
    }
    set<ll> s;
    for(const pair<ll, pair<int, ll>> & x : m){
        if(x.se.fi > 1){
            s.insert(x.fi);
            ans += x.se.se;
            cnt += x.se.fi;
        }
    }
    ll mask = 0;
    for(int x : s){
        mask |= x;
    }
    for(int i=0;i<n;++i){
        if(s.count(a[i].fi)) continue;
        // if((mask & a[i].fi) == a[i].fi){
        //     ans += a[i].se;
        //     cnt++;
        // }
        for(ll x : s){
            if((x & a[i].fi) == a[i].fi){
                ans += a[i].se;
                cnt++;
                break;
            }
        }
    }
    printf("%lld\n", cnt>1? ans : 0);
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