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
int a[100002];

int main(){
    scanf("%d", &n);
    for(int i=0;i<n;++i){
        scanf("%d", a+i);
    }
    vector<int> vp, vn ;
    ll sum = 0;
    for(int i=0;i<n;++i){
        if(a[i] %2 == 0){
            a[i] /= 2;
        }
        else if(a[i] > 0){
            vp.pb(i);
            a[i]/=2;
        }
        else if(a[i] < 0){
            vn.pb(i);
            a[i]/=2;
        }
        sum += a[i];
    }
    if(sum > 0){
        for(int x : vn){
            a[x]--;
            sum--;
            if(sum == 0) break;
        }
    }
    else if(sum < 0){
        for(int x : vp){
            a[x]++;
            sum++;
            if(sum == 0) break;
        }
    }
    for(int i=0;i<n;++i){
        printf("%d\n", a[i]);
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