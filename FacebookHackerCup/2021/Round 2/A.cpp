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
int s[1000002];

int main(){
    scanf("%d", &t);
    for(int cc=1;cc<=t;++cc) {
        printf("Case #%d: ", cc);
        scanf("%d %d", &n, &m);
        vector<vector<int>> p(n+1, vector<int>(m, 0));        
        vector<vector<int>> d(n+1, vector<int>(m, -1));
        for(int i=0;i<m;++i) {
            scanf("%d", &p[0][i]);
        }
        for(int i=1;i<=n;++i) {
            for(int j=0;j<m;++j) {
                scanf("%d", &p[i][j]);
            }
        }
        int ans = 0;
        for(int i=n-1;i>=0;--i) {
            map<int, vector<int>> cnt;
            set<int> has;
            for(int j=0;j<m;++j) {
                cnt[p[i+1][j]].push_back(j);
                has.insert(j);
            }
            for(int j=0;j<m;++j) {
                auto it = cnt.find(p[i][j]);
                if (it == cnt.end() || it->second.empty()) continue;
                d[i][j] = it->second.back();
                it->second.pop_back();
                has.erase(d[i][j]);
            }
            for(int j=0;j<m;++j) {
                if (d[i][j] == -1) {
                    d[i][j] = *has.begin();
                    has.erase(has.begin());
                }
            }
        }
        for(int i=0;i<m;++i) {
            int now = i;
            int c = 0;
            for(int j=0;j<n;++j) {
                int next = d[j][now];
                if (p[j][now] != p[j+1][next]) c++;
                now = next;
            }
            ans += max(c-1, 0);
        }
        printf("%d\n", max(ans, 0));
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