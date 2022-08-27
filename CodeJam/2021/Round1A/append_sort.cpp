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
ll a[1000];
char s[103][500];

int checkPrefix(char *a, char *b) {
    int la, lb;
    la = strlen(a);
    lb = strlen(b);
    for(int i=0;i<min(la, lb);++i) {
        if(a[i] > b[i]) {
            return -1;
        } else if (a[i] < b[i]) {
            return 1;
        }
    }
    return 0;
}

int compare(char *a, char *b) {
    int la, lb;
    la = strlen(a);
    lb = strlen(b);
    if (lb != la) {
        return lb > la ? 1 : -1;
    }
    for(int i=0;i<la;++i) {
        if(a[i] > b[i]) {
            return -1;
        } else if (a[i] < b[i]) {
            return 1;
        }
    }
    return 0;
}

void appendDigits(char *a, int n, char ed) {
    int la = strlen(a);
    for(int i=la;i<n;++i) {
        if (i == n-1) {
            a[i] = ed;
        } else {
            a[i] = 0;
        }
    }
}

void addOne(char *a, int n) {
    // printf("addone: %s %d\n", a, n);
    int la = strlen(a);
    bool nine = true;
    for(int i=la-n;i<la;++i) {
        if (a[i] != '9') {
            nine = false;
        }
    }
    if (nine) {
        for(int i=la-n-1;i<la;++i) {
            a[i] = '0';
        }
        a[la] = '0';
    } else {
        for(int i=la-1;i>=la-n;i--){
            if (a[i] == '9') {
                a[i] = '0';
            } else {
                a[i]++;
                break;
            }
        }
    }
}

int solve(char *a, char *b) {
    int la, lb;
    la = strlen(a);
    lb = strlen(b);
    if (compare(a, b) == 1) {
        return 0;
    }
    int c = 0;
    for(int i=0;i<la;++i) {
        switch (c) {
        case 0:
            if (b[i] == 0) {
                b[i] = a[i];
            } else {
                if (a[i] < b[i]) {
                    c = -1;
                } else if (a[i] > b[i]) {
                    c = 1;
                }
            }
        break;
        case -1:
            if (b[i] == 0) {
                b[i] = '0';
            }
        break;
        case 1:
            if (b[i] == 0) {
                b[i] = '0';
            }
        break;
        }
    }
    int cc = checkPrefix(a, b);
    if (cc == -1) {
        b[strlen(b)] = '0';
    } else if(cc == 0) {
        addOne(b, strlen(b) - lb);
    }
    return strlen(b) - lb;
}

int main(){
    scanf("%d", &t);
    for(int cc=1;cc<=t;++cc) {
        printf("Case #%d: ", cc);
        scanf("%d", &n);
        memset(s, 0, sizeof s);
        for(int i=0;i<n;++i) {
            scanf("%s", s[i]);
        }
        int ans = 0;
        for(int i=1;i<n;++i) {
            ans += solve(s[i-1], s[i]);
        }
        printf("%d\n", ans);
        // for(int i=0;i<n;++i) printf("%s\n", s[i]);
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