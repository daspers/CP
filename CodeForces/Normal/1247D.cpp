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
int cnt[100002];
int psum[100002];
vector<int> adj[100002], p[100002];
vector<ll> v;

ll pangkat(int base, int exp){
    ll ans = 1;
    for(ll val=base;exp;exp>>=1){
        if(exp&1)
            ans = 1LL*ans*val;
        val = 1LL*val*val;
    }
    return ans;
}

int main(){
    scanf("%d %d", &n, &k);
    int tot = 0;
    for(int i=0;i<n;++i){
        scanf("%d", a+i);
        cnt[a[i]]++;
    }
    v.pb(1);
    for(int i=k;i<=k;++i){
        int ub = pow(1e10, 1.0/i);
        for(int j=2;j<=ub;++j){
            v.pb(pangkat(j, i));
        }
    }
    for(int i=1;i<=100000;++i) psum[i] = psum[i-1] + cnt[i];
    sort(a, a+n);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    // printArray(v.data(), 200);
    // printArray(a, n);
    vector<int> b(a, a+n);
    b.erase(unique(b.begin(), b.end()), b.end());
    ll ans = 0;
    if(k == 2 && false){
        for(int i=0;i<b.size();++i){
            ans += 1LL * cnt[b[i]] * (cnt[b[i]] - 1) /2;
            int tmp = b[i];
            int sq = sqrt(tmp);
            vector<int> w;
            ll a1 = 1, a2 = 1;
            for(int j=2;j<=sq && tmp > 1;++j){
                if(tmp % j ==0){
                    int cc = 0;
                    do{
                        cc++;
                        tmp /= j;
                    } while(tmp % j ==0);
                    if(cc & 1) a1 *= j;
                    else a2 *= pangkat(j, cc/2);
                }
            }
            if(tmp > 1) a1 *= tmp;
            for(int j=a2 + 1;j<=100000;++j){
                ll now = 1LL * a1 * j * j / b[i];
                if(now > b.back()) break;
                ans += 1LL*cnt[now]*cnt[b[i]];
            }
        }
    }
    else {
        for(int i=0;i<b.size();++i){
            int st = upper_bound(v.begin(), v.end(), 1LL*b[i]*b[i]) - v.begin();
            int ed = upper_bound(v.begin(), v.end(), 1LL*b[i]*b.back()) - v.begin();
            int contain = lower_bound(v.begin(), v.end(), 1LL*b[i]*b[i]) - v.begin();
            if(contain < v.size() && v[contain] == 1LL*b[i]*b[i]){
                // cerr<<"lol "<<b[i]<<endl;
                ans += 1LL * cnt[b[i]] * (cnt[b[i]] - 1) /2;
            }
            // ans += 1LL * (psum[v[ed-1]/b[i]] - psum[v[st-1]/b[i]]) * cnt[b[i]];
            // debug5(b[i], v[st], v[ed], st, ed);
            for(int j=st;j<ed;++j){
                if(v[j] % b[i] == 0){
                    int lol = v[j] / b[i];
                    if(cnt[lol]) {
                        // debug3(b[i], lol, cnt[lol] * cnt[b[i]]);
                        ans += 1LL * cnt[lol] * cnt[b[i]];
                    }
                }
            }
        }
    }
    printf("%lld\n", ans);
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