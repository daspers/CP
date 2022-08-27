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
int a[200002];
int b[200002];
int c[200002];
int pos[200002];
int ac[200002];
int bc[200002];
int cc[200002];
int mab[200002];

int hitung(int st, int pem, int ed){
    int total = ac[st];
    total += (bc[pem] - bc[st]);
    total += (cc[ed] - cc[pem]);
    return total;
}

int hitung2(int st, int pem, int ed){
    int total = ac[st];
    total += (bc[pem] - bc[st]);
    total += (cc[ed] - cc[pem]);
    return total;
}


int main(){
    scanf("%d %d %d", &n, &m, &k);
    int tot = n + m + k;
    for(int i=0;i<n;++i){
        scanf("%d", a+i);
        pos[a[i]] = 1;
    }
    for(int i=0;i<m;++i){
        scanf("%d", b+i);
        pos[b[i]] = 2;
    }
    for(int i=0;i<k;++i){
        scanf("%d", c+i);
        pos[c[i]] = 3;
    }
    for(int i=1;i<=tot;++i){
        ac[i] = ac[i-1] + (pos[i] == 1);
        bc[i] = bc[i-1] + (pos[i] == 2);
        cc[i] = cc[i-1] + (pos[i] == 3);
    }
    mab[tot] = bc[tot];
    for(int i=tot-1;i>=0;--i){
        mab[i] = max(mab[i+1], bc[i] + cc[tot] - cc[i]);
    }
    int ans = 0;
    for(int i=0;i<=tot;++i){
        ans = max(ans, ac[i] + mab[i] - bc[i]);
    }
    printf("%d\n", tot - ans);
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