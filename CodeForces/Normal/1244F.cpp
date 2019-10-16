#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-9
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
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
char s[200002];
char r[200002];
char a[200002];
char pre[200002];
char ne[256];


int main(){
    ne['W'] = 'B';
    ne['B'] = 'W';
    scanf("%d %d", &n, &k);
    scanf("%s", s);
    bool termin = false;
    int cyc = -1;
    memcpy(a, s, n+1);
    memcpy(r, s, n+1);
    vector<int> c, tmp;
    vector<vector<int>> d;
    for(int i=0;i<n;++i){
        if(s[i]!=s[(n + i-1)%n] && s[i] != s[(i+1)%n]){
            c.pb(i);
        }
    }
    if(c.size() == n){
        cyc = 2;
    }
    else if(c.size() > 0){
        tmp.pb(c[0]);
        for(int i=1;i<c.size();++i){
            if(c[i] == c[i-1]+1){
                tmp.pb(c[i]);
            }
            else {
                d.pb(tmp);
                tmp.clear();
                tmp.pb(c[i]);
            }
        }
        if(c.front() == 0 && c.back() == n-1){
            tmp.insert(tmp.end(), d[0].begin(), d[0].end());
            d[0] = tmp;
        }
        else if(tmp.size()>0) {
            d.pb(tmp);
        }
        for(const vector<int> & x : d){
            // printArray(x);
            int time = (x.size()+1)/2;
            if(time <= k){
                for(int j=0;j<time;++j){
                    // printf("lol\n");
                    r[x[j]] = ne[s[x.front()]];
                    r[x[(int)x.size()-1-j]] = ne[s[x.back()]];
                }
            }
            else {
                for(int j=0;j<k;++j){
                    // cerr<<"modify "<<j<<" "<<(int)x.size()-1-j<<endl;
                    r[x[j]] = ne[s[x.front()]];
                    r[x[(int)x.size()-1-j]] = ne[s[x.back()]];
                }
                if(k&1){
                    for(int j=k;j<(int)x.size()-k;++j){
                        r[x[j]] = ne[s[x[j]]];
                    }
                }
            }
        }
    }
    if(cyc > 0){
        memcpy(s, a, n+1);
        for(int i=0;i<k%cyc;++i){
            for(int j=0;j<n;++j){
                if(s[j]!=s[(n + j-1)%n] && s[j] != s[(j+1)%n]){
                    r[j] = ne[s[j]];
                }
                else {
                    r[j] = s[j];
                }
            }
            memcpy(s, r, n+1);
        }
    }
    printf("%s\n", r);
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