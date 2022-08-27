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
char s[5005];
int ca[5005];
int ct[5005];
int cg[5005];
int cc[5005];

int main(){
    scanf("%d %s", &n, s+1);
    for(int i=1;i<=n;++i){
        ca[i] = ca[i-1];
        cg[i] = cg[i-1];
        cc[i] = cc[i-1];
        ct[i] = ct[i-1];
        if(s[i] == 'A') ca[i]++;
        else if(s[i] == 'T') ct[i]++;
        else if(s[i] == 'G') cg[i]++;
        else if(s[i] == 'C') cc[i]++;
    }
    int ans = 0;
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            if((ca[j]-ca[i-1] == ct[j] - ct[i-1]) && (cc[j]-cc[i-1] == cg[j]-cg[i-1]))
                ans++;
        }
    }
    printf("%d\n", ans);
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