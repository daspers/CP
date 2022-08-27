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
int a[10];
int dp[10][91][2000];
int offset = 1000;

int solve(int dig, int remd, int remsum){
    int &ans = dp[dig][remd][remsum];
    if(ans == -1){
        if(dig == 0){
            if(remd) ans = 0;
            else ans = abs(remsum - offset) % 11 == 0;
        }
        else {
            int csum = -dig*a[dig];
            ans = 0;
            for(int i=0;i<=a[dig] && i<=remd;++i){
                assert(remsum+csum>=0 && remsum+csum<2000);
                ans = max(ans, solve(dig-1, remd-i, remsum+csum));
                csum += 2*dig;
            }
        }
    }
    return ans;
}

int main(){
    scanf("%d", &t);
    for(int cc=1;cc<=t;++cc){
        int tot = 0;
        for(int i=1;i<10;++i){
            scanf("%d", a+i);
            if(a[i] > 20) exit(0);
            tot += a[i];
        }
        int pos = (tot + 1)/2;
        memset(dp, -1, sizeof dp);
        int ans = solve(9, pos, offset);
        printf("Case #%d: ", cc);
        puts(ans ? "YES" : "NO");
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