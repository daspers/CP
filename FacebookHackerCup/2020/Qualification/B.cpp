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
char s[1000000];

int main(){
    scanf("%d", &t);
    for(int cc=1;cc<=t;++cc){
        scanf("%d", &n);
        scanf("%s", s);
        // int cnta = 0;
        // for(int i=0;i<n;++i) cnta += s[i] == 'A';
        // printf("Case #%d: %s\n", cc, abs(n-2*cnta) == 1 ? "Y" : "N");
        stack<char> a;
        stack<char> b;
        deque<char> w;
        for(int i=n-1;i>=0;--i) b.push(s[i]);
        bool forward = true;
        while(!(b.empty() && forward)){
            if(w.size() < 3){
                if(forward){
                    w.push_back(b.top());
                    b.pop();
                }
                else {
                    if(a.empty()) forward = true;
                    else {
                        w.push_back(a.top());
                        a.pop();
                    }
                }
            }
            else {
                for(char x : w){
                    printf("%c ", x);
                }
                puts("");
                if(w[0] != w[2]){
                    char tmp = w[1];
                    w.clear();
                    w.push_back(tmp);
                }
                else if(w[0] != w[1]){
                    char tmp = w[2];
                    w.clear();
                    w.push_back(tmp);
                }
                else {
                    a.push(w.front());
                    w.pop_front();
                }
                for(char x : w){
                    printf("%c ", x);
                }
                puts("");
            }
        }
        debug(a.size());
        debug(b.size());
        debug(w.size());
        printf("Case #%d: ", cc);
        if(w.size() + a.size() + b.size() == 1) puts("Y");
        else puts("N");
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