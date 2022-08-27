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

const ll mod = 1e9;
const double PI = acos(-1);

int n,i,j,k,t;
char s[2002];

int main(){
    scanf("%d", &t);
    for(int cc=1;cc<=t;++cc){
        printf("Case #%d: ", cc);
        scanf("%s", s);
        n = strlen(s);
        pii curr = {0, 0};
        stack<pii> d;
        stack<int> mul;
        for(int i=0;i<n;++i){
            char c = s[i];
            if('2'<=c && c<='9'){
                mul.push(c-'0');
            }
            else if(c == '('){
                d.push(curr);
                curr = {0, 0};
            }
            else if(c == ')'){
                int cmul = mul.top(); mul.pop();
                pii cd = d.top(); d.pop();
                curr.fi = 1LL * curr.fi * cmul % mod;
                curr.se = 1LL * curr.se * cmul % mod;
                curr.fi = (curr.fi + cd.fi) % mod;
                curr.se = (curr.se + cd.se) % mod;
            }
            else {
                if (c == 'N'){
                    curr.fi = (curr.fi - 1) % mod;
                }
                else if(c =='S'){
                    curr.fi = (curr.fi + 1) % mod;
                }
                else if(c == 'E'){
                    curr.se = (curr.se + 1) % mod;
                }
                else {
                    curr.se = (curr.se - 1) % mod;
                }
            }
        }
        curr.fi = (mod + curr.fi) % mod;
        curr.se = (mod + curr.se) % mod;
        printf("%d %d\n", curr.se+1, curr.fi+1);
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