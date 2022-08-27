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
ll s;
int take;
pii a[200002];

bool coba(int val){
    ll sum = 0;
    vector<int> v;
    int ct = take;
    for(int i=0;i<n;++i){
        if(a[i].se >= val){
            if(a[i].fi >= val){
                sum += a[i].fi; ct--;
            }
            else {
                v.pb(a[i].fi);
            }
        }
        else {
            sum += a[i].fi;
        }
    }
    if(ct>0 && v.size() < ct) return false;
    if(ct >= 0){
        sum += 1LL * val * ct;
    }
    sort(v.begin(), v.end());
    for(int i=0;i+ct<v.size() && i<v.size();++i){
        sum += v[i];
    }
    return sum <= s;
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %lld", &n, &s);
        int mi = 1e9, ma = 1;
        for(int i=0;i<n;++i){
            scanf("%d %d", &a[i].fi, &a[i].se);
            mi = min(mi, a[i].fi);
            ma = max(ma, a[i].se);
        }
        take = (n+1)/2;
        int l=mi, r=ma;
        while(l < r){
            int mid = (l + r + 1)/2;
            if(coba(mid)){
                l = mid;
            }
            else {
                r = mid-1;
            }
        }
        printf("%d\n", l);
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