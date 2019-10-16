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
#define debug6(a, b, c, d, e, f) cerr<<#a<<"="<<(a)<<" ";debug5(b, c, d, e, f)
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
vector<int> v;
ll psum[100002];
ll ssum[100002];
int pcnt[100002];
int scnt[100002];
map<int, int> cnt;

int main(){
    ll k;
    scanf("%d %lld", &n, &k);
    a[0] = 0; cnt[0]=0;
    for(int i=1;i<=n;++i){
        scanf("%d", a+i);
        cnt[a[i]]++;
    }
    a[n+1] = 1000000001; cnt[1000000001] = 0;
    sort(a+1, a+n+1);
    v = vector<int>(a, a+n+2);
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i=1;i<v.size();++i){
        psum[i] = psum[i-1] + 1LL*v[i]*cnt[v[i]];
        pcnt[i] = pcnt[i-1] + cnt[v[i]];
    }
    for(int i=(int)v.size()-2;i>=0;--i){
        ssum[i] = ssum[i+1] + 1LL*(v.back() - v[i]) * cnt[v[i]];
        scnt[i] = scnt[i+1] + cnt[v[i]];
    }
    int ans = a[n] - a[1];
    for(int i=(int)v.size()-2;i>0;--i){
        ll curr = 1LL*(v.back() - v[i])*scnt[i+1] - ssum[i+1];
        ll ma = v[i], mi;
        ll ncurr = curr;
        if(curr > k){
            ll tmp = (curr - k + (scnt[i+1] - 1)) / scnt[i+1];
            ncurr = 1LL*(v.back() - v[i] - tmp)*scnt[i+1] - ssum[i+1];
            ma = v[i] + tmp;
        }
        ll rem = k - ncurr;
        int l=1, r=i;
        while(l < r){
            int mid = (l+r)/2;
            ll tsum = 1LL*v[mid] * pcnt[mid-1] - psum[mid-1];
            if(tsum >= rem){
                r = mid;
            }
            else {
                l = mid +1;
            }
        }
        ll lcurr = 1LL*v[r] * pcnt[r-1] - psum[r-1];
        mi = v[r];
        if(lcurr > rem){
            ll tmp = (lcurr - rem + (pcnt[r-1] - 1)) / pcnt[r-1];
            lcurr = 1LL*(v[r] - tmp)*pcnt[r-1] - psum[r-1];
            mi = v[r] - tmp;
        }
        ans = min((ll)ans, ma - mi);
        if(curr >= k){
            break;
        }
    }
    for(int i=1;i<(int)v.size()-1;++i){
        ll curr = 1LL*(v[i])*pcnt[i-1] - psum[i-1];
        ll ma, mi = v[i];
        ll ncurr = curr;
        if(curr > k){
            ll tmp = (curr - k + (pcnt[i-1] - 1)) / pcnt[i-1];
            ncurr = 1LL*(v[i] - tmp)*pcnt[i-1] - psum[i-1];
            mi = v[i] - tmp;
        }
        ll rem = k - ncurr;
        int l=i, r=(int)v.size()-2;
        while(l < r){
            int mid = (l+r+1)/2;
            ll tsum = 1LL*(v.back() - v[mid]) * scnt[mid+1] - ssum[mid+1];
            if(tsum >= rem){
                l = mid;
            }
            else {
                r = mid-1;
            }
        }
        ll rcurr = 1LL*(v.back() - v[l]) * scnt[l+1] - ssum[l+1];
        ma = v[r];
        if(rcurr > rem){
            ll tmp = (rcurr - rem + (scnt[l+1] - 1)) / scnt[l+1];
            rcurr = 1LL*(v[r] - tmp)*scnt[l+1] - ssum[l+1];
            ma = v[r] + tmp;
        }
        ans = min((ll)ans, ma - mi);
        if(curr >= k){
            break;
        }
    }
    printf("%d\n", ans);
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