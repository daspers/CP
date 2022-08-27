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
ll m;
ll a[1002];
ll cnt[60];

ll greedy_l(int idx, ll now, ll val){
    for(int i = idx;i>=0;--i){
        ll tmp = 1LL << i;
        if(cnt[i] == (n - cnt[i])){
            val += tmp;
            now += cnt[i] * tmp;
        }
        else if(cnt[i] > (n - cnt[i])){
            val += 1LL << i;
            now += (n - cnt[i]) * tmp;
        }
        else {
            now += cnt[i] * tmp;
        }
    }
    return now <= m ? val : -1;
}

int main(){
    scanf("%d", &t);
    for(int cc=1;cc<=t;++cc){
        scanf("%d %lld", &n, &m);
        vector<ll> v;
        for(int i=0;i<n;++i){
            scanf("%lld", a+i);
            v.pb(a[i]);
        }
        ll ans = -1;
        for(int i=50;i>=0;--i){
            ll tmp = (1LL << i);
            cnt[i] = 0;
            for(int j=0;j<n;++j){
                if(a[j] & tmp) ++cnt[i];
            }
        }
        int rem = 2;
        ll sum = 0;
        ll val = 0;
        for(int i=50;i>=0 && rem;--i){
            ll tmp = 1LL << i;
            ll lol = greedy_l(i-1, sum + tmp * (n - cnt[i]), val | tmp);
            // debug2(i, lol);
            if(lol != -1){
                val |= tmp;
                sum += tmp * (n - cnt[i]);
                // cerr<<"add "<<i<<"*"<<(n - cnt[i])<<endl;
            }
            else {
                sum += tmp * cnt[i];
                // cerr<<"add "<<i<<"*"<<(cnt[i])<<endl;
            }
        }
        if(sum <= m){
            ans = val;
        }
        // debug(cc);
        // for(ll i=0;i<=2*m;++i){
        //     ll sum = 0;
        //     for(int j=0;j<n;++j){
        //         sum += a[j] ^ i;
        //     }
        //     printf("%lld ", sum);
        // }
        // puts("");
        // sort(a, a+n);
        // sort(v.begin(), v.end());
        // v.erase(unique(v.begin(), v.end()), v.end());
        // ll ans = -1;
        // printArray(v);
        // // ll lb = 0;
        // // for(ll i=v.front();i<=v.back();++i){
        // //     ll sum = 0;
        // //     for(int j=0;j<n;++j){
        // //         sum += i ^ a[j];
        // //     }
        // //     vector<ll>::iterator it = lower_bound(v.begin(), v.end(), i);
        // //    if(it != v.end() && *it == i) printf("!");
        // //     printf("%lld ", sum);
        // // }
        // puts("");
        // for(int i=(int)v.size()-1;i>=0;--i){
        //     ll sum = 0;
        //     for(int j=0;j<n;++j){
        //         sum += v[i] ^ a[j];
        //     }
        //     if(sum <= m){
        //         ans = i;
        //     }
        // }
        // ll l = 0, r = m;
        // while(l < r){
        //     ll mid = (l+r)/2;
        // }
        printf("Case #%d: %lld\n", cc, ans);
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