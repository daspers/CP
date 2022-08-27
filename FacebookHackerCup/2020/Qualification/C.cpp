#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-9
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define debug2(a, b) cerr<<#a<<"="<<(a)<<" ";debug(b)
#define debug3(a, b, c) cerr<<#a<<"="<<(a)<<" ";debug2(b, c)
#define debug4(a, b, c, d) cerr<<#a<<"="<<(a)<<" ";debug3(b, c, d)
#define debug5(a, b, c, d, e) cerr<<#a<<"="<<(a)<<" ";debug4(b, c, d, e)
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<class T>
void printArray(const T * a, int n, ostream& out = cerr);
template<class T>
void printArray(const vector<T> &arr, ostream& out = cerr);

const ll mod = 1e9+7;
const double PI = acos(-1);

int n,i,j,k,t;
pii a[800005];
int dp[800005][2]; // 0 - left, 1 - right

int main(){
    scanf("%d", &t);
    for(int cc=1;cc<=t;++cc){
        printf("Case #%d: ", cc);
        scanf("%d", &n);
        for(int i=0;i<n;++i){
            scanf("%d %d", &a[i].fi, &a[i].se);
        }
        sort(a, a+n);
        dp[0][0] = dp[0][1] = a[i].se;
        int ans = max(dp[0][0], dp[0][1]);
        map<int, int> wow;
        wow[a[0].fi] = a[0].se;
        wow[a[0].fi + a[0].se] = a[0].se;
        for(int i=1;i<n;++i){
            dp[i][0] = dp[i][1] = a[i].se;
            if(wow.count(a[i].fi)) {
                wow[a[i].fi + a[i].se] = max(wow[a[i].fi + a[i].se], a[i].se + wow[a[i].fi]);
            }
            else {
                wow[a[i].fi + a[i].se] = max(wow[a[i].fi + a[i].se], a[i].se);   
            }
            if(wow.count(a[i].fi - a[i].se)){
                wow[a[i].fi] = max(wow[a[i].fi], a[i].se + wow[a[i].fi - a[i].se]);
            }
            else {
                wow[a[i].fi] = max(wow[a[i].fi], a[i].se);
            }
        }
        for(const pii &x : wow){
            ans = max(ans, x.se);
        }
        printf("%d\n", ans);
    }
    return 0;
}

/* Template Function */
template<class T>
void printArray(const T * a, int n, ostream& out){
    for(int i=0;i<n;++i){
        out<<a[i]<<" ";
    }
    out<<endl;
}

template<class T>
void printArray(const vector<T> &arr, ostream& out){
    for(const T& x : arr){
        out<<x<<" ";
    }
    out<<endl;
}