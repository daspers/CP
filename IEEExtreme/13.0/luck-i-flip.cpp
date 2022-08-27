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
int b;
char s[100][30];
int a[100];
int cnt[100];

int main(){
    scanf("%d", &b);
    for(int i=0;i<b;++i){
        scanf("%s", s[i]);
        n = strlen(s[i]);
        a[i] = 0;
        for(int j=0;j<n;++j){
            a[i] = 2*a[i] + s[i][j] - '0';
        }
    }
    int ma = 1<<n;
    for(int i=0;i<ma;++i){
        int ma = 0;
        int ccount = 0;
        int cc = 0;
        for(int j=0;j<b;++j){
            int tcount = n - __builtin_popcount(a[j] ^ i);
            if(tcount > ccount){
                ccount = tcount;
                ma = j;
                cc = 1;
            }
            else if(tcount == ccount) {
                ++cc;
            }
        }
        if(cc == 1){
            cnt[ma]++;
        }
    }
    int ans = *min_element(cnt, cnt+b);
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