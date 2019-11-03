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
char s[300004];
vector<char> a, b;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%s", s);
        n = strlen(s);
        a.clear(); b.clear();
        for(int i=0;i<n;++i){
            if(s[i] & 1){
                a.pb(s[i]);
            }
            else {
                b.pb(s[i]);
            }
        }
        i = j = 0;
        for(;i<a.size() && j<b.size();){
            if(a[i] > b[j]){
                printf("%c", b[j]);
                ++j;
            }
            else {
                printf("%c", a[i]);
                ++i;
            }
        }
        for(;i<a.size();++i){
            printf("%c", a[i]);
        }
        for(;j<b.size();++j){
            printf("%c", b[j]);
        }
        puts("");
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