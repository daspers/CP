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
pair<pii, int> a[1002];
int b[2002];
char ans[2002];

int main(){
    scanf("%d", &t);
    for(int cc=1;cc<=t;++cc){
        printf("Case #%d: ", cc);
        scanf("%d", &n);
        memset(b, 0, sizeof b);
        for(int i=0;i<n;++i){
            scanf("%d %d", &a[i].fi.fi, &a[i].fi.se);
            b[a[i].fi.fi] += 1;
            b[a[i].fi.se] -=1;
            a[i].se = i;
        }
        for(int i=1;i<=24*60;++i){
            b[i] += b[i-1];
        }
        bool possible = true;
        // for(int i=0;i<=24*60;++i){
        //     if(b[i] > 2){
        //         possible = false;
        //     }
        // }
        // printArray(b, 24*60+1);
        if(possible){
            sort(a, a+n, [](const pair<pii, int> &a, const pair<pii, int> &b){
                // if(a.fi.se == b.fi.se){
                //     return a.fi.fi < b.fi.fi;
                // }
                // return a.fi.se < b.fi.se;
                return a.fi < b.fi;
            });
            int x = -1, y = -1;
            for(int i=0;i<n;++i){
                if(x <= a[i].fi.fi){
                    x = a[i].fi.se;
                    ans[a[i].se] = 'C';
                }
                else if(y <= a[i].fi.fi) {
                    y = a[i].fi.se;
                    ans[a[i].se] = 'J';
                }
                else{
                    possible = false;
                    break;
                }
                // printf("%d %d %c\n", a[i].fi.fi, a[i].fi.se, ans[a[i].se]);
            }
            ans[n] = 0;
        }
        if (possible)
            printf("%s\n", ans);
        else {
            puts("IMPOSSIBLE");
        }
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