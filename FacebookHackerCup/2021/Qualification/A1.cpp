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
char s[200];
int cnt[30];

int main(){
    scanf("%d", &t);
    for(int cc=1;cc<=t;++cc) {
        printf("Case #%d: ", cc);
        scanf("%s", s);
        n = strlen(s);
        memset(cnt, 0, sizeof cnt);
        int c=0, v=0;
        for(int i=0;i<n;++i) {
            cnt[s[i]-'A']++;
            if (s[i] == 'A' || s[i] =='I' || s[i] == 'U' || s[i] =='E' || s[i] == 'O') {
                v++;
            } else {
                c++;
            }
        }
        int ans = n * 2;
        for(int i='A';i<='Z';++i) {
            int idx = i - 'A';
            if (i == 'A' || i =='I' || i == 'U' || i =='E' || i == 'O') {
                int ot = v - cnt[idx];
                ans = min(ans, c + ot * 2);
            } else {
                int ot = c - cnt[idx];
                ans = min(ans, v + ot * 2);
            }
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