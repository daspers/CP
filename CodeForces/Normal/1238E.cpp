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
int m;
char s[100002];
int cnt[20][20];
ll cost[1<<20];
ll dp[1<<20];

int main(){
    scanf("%d %d", &n, &m);
    scanf("%s", s);
    for(int i=1;i<n;++i){
        if(s[i] != s[i-1]){
            cnt[s[i]-'a'][s[i-1]-'a']++;
            cnt[s[i-1]-'a'][s[i]-'a']++;
        }
    }
    dp[0] = cost[0] = 0;
    int m2 = 1<<m;
    for(int i=1;i<m2;++i){
        cost[i] = 0;
        for(int j=0;j<m;++j){
            if((i & (1<<j)) == 0) continue;
            for(int k=0;k<m;++k){
                if((i & (1<<k))) continue;
                cost[i] += cnt[j][k];
            }
        }
    }
    for(int i=1;i<m2;++i){
        dp[i] = 1e18;
        for(int j=0;j<m;++j){
            if(i&(1<<j)){
                dp[i] = min(dp[i], dp[i ^ (1<<j)] + cost[i]);
            }
        }
    }
    printf("%lld\n", dp[m2-1]);
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