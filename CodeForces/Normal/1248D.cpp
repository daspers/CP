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
char s[6000003];

int hitung(int l, int r){
    int bal = 0;
    int cnt = 0;
    for(int i=l;i<=r;++i){
        if(s[i] == '('){
            bal++;
        }
        else {
            if(--bal == 0){
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    scanf("%d", &n);
    scanf("%s", s);
    vector<int> ri, le;
    // for(int i=0;i<n;++i) s[i+n] = s[i];
    int bal = 0;
    for(int i=0;i<n;++i){
        if(s[i]==')'){
            if(!le.empty()) le.pop_back();
            else ri.pb(i);
        }
        else le.pb(i);
    }
    if(le.size() != ri.size()){
        return puts("0\n1 1"), 0;
    }
    if(le.size() > 1){
        int ans = 1 + hitung(ri.back()+1, le.front()-1);
        int c1 = 1, c2 = 1;
        swap(s[le[0]], s[ri[ri.size()-1]]);
        int tmp = 1 + hitung(ri[ri.size()-1]+1, le[0]-1);
        if(tmp > ans){
            ans = tmp;
            c1 = ri.back()+2, c2 = le.front();
        }
        swap(s[le[0]], s[ri[ri.size()-1]]);
        swap(s[le[1]], s[ri[ri.size()-2]]);
        if(le.size() > 2){
            tmp = 1 + hitung(ri[ri.size()-2]+1, le[1]-1);
            if(tmp > ans){
                ans = tmp;
                c1 = s[le[1]] + 1;
                c2 = s[ri[ri.size()-2]] + 1;
            }
        }
        else {
            tmp = hitung(0, n-1);
            if(tmp > ans){
                ans = tmp;
                c1 = s[le[1]] + 1;
                c2 = s[ri[ri.size()-2]] + 1;
            }
        }
        printf("%d\n%d %d\n", ans, c1, c2);
    }
    else if(le.size()){
        int ans = 1 + hitung(ri.back()+1, le.front()-1);
        int c1 = 1, c2 = 1;
        swap(s[le.front()], s[ri.front()]);
        int tmp = hitung(0, n-1);
        if(tmp > ans){
            ans = tmp;
            c1 = ri.back()+1, c2 = le.front()+1;
        }
        printf("%d\n%d %d\n", ans, c1, c2);
    }
    else {
        // Case swap random :/
        int ans = hitung(0, n-1);
        printf("%d\n1 1\n", ans);
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