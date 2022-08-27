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
pii a[100005];
int pmi[100004];
int smi[100004];

int main(){
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;++i){
        scanf("%d", &a[i].fi);
    }
    for(int i=0;i<n;++i){
        scanf("%d", &a[i].se);
    }
    ll ans = max(a[n-1].fi - a[n-1].se, 0);
    if(k == 0){
        ll sum = 0;
        for(int i=n-1;i>=0;--i){
            sum += a[i].fi;
            ans = max(ans, sum - a[i].se);
        }
    }
    else if (k == 1) {
        ll sum = 0;
        if(k > 2){
            sort(a, a+n-1, [](const pii &a, const pii &b){
                if(a.se == b.se) return a.fi > b.fi;
                return a.se < b.se;
            });
        }
        // from [2..N-1] to N (to k = 1 only)
        sum = 0;
        for(int i=n-1;i>0;--i){
            sum += a[i].fi;
            ans = max(ans, sum - a[i].se);
            ans = max(ans, sum - a[i].se + a[0].fi - a[0].se);
        }
        // from [1..N-1] to anywhere (cycle) whitout N (to all)
        sum = 0;
        int mi = 1e9;
        for(int i=0;i<n-1;++i){
            sum += a[i].fi;
            mi = min(mi, a[i].se);
        }
        ans = max(ans, sum - mi);
        ans = max(ans, sum - mi + a[n-1].fi - a[n-1].se);
        // from 1 to N, skip one of [2..N-1] (to k=1 only)
        sum = a[n-1].fi + a[n-2].fi;
        mi = 1e9;
        int mifi = 1e9;
        for(int i=n-3;i>=0;--i){
            sum += a[i].fi;
            mi = min(mi, a[i+1].se);
            mifi = min(mifi, a[i+1].fi);
            ans = max(ans, sum - a[i].se - mifi);
            ans = max(ans, sum - a[i].se - mi);
        }
        // if(k > 2) {
        //     pmi[0] = 1e9;
        //     smi[n-2] = 1e9;
        //     for(int i=1;i<n-1;++i){
        //         pmi[i] = min(pmi[i-1], a[i-1].se);
        //     }
        //     for(int i=n-3;i>=0;--i){
        //         smi[i] = min(smi[i+1], a[i+1].se);
        //     }
        //     // new DAG from [1..N-1] to N, skip one of [1..N-1]
        //     sum = 0;
        //     for(int i=0;i<n;++i){
        //         sum += a[i].fi;
        //     }
        //     for(int i=0;i<n-1;++i){
        //         ans = max(ans, sum - a[i].fi - min(smi[i], pmi[i]));
        //         ans = max(ans, sum - min(smi[i], pmi[i]) - a[i].se);
        //     }
        // }
    }
    else if(k&1) {
    //k ganjil dan k > 1

        //ga bs ambil semua klo start dari index 2...harus salah coba salah satu diskip antara 1...n (kecuali 2 tentu saja) dan cari min(a[1], a[3..n])...
        //jawabannya adalah sum semua a - min(a[1], a[3..n]) - d[2]
        //assume klo mulai dari 2
        ll jawab = 0;
        ll minimum = 1e9;
        ll jumlahSemua = 0;
        for(i=0;i<n;i++){
            jumlahSemua += a[i].fi;
            if(i == 2){
                continue;
            }else{
                minimum = min(minimum, (ll)a[i].fi);
            }
        }
        ans = max(ans, jumlahSemua - minimum - a[2].se);
        //selain itu..bs ambil semua
        ll minim = 1e9;
        ll sum = 0;
        for(i=0;i<n;i++){
            sum += a[i].fi;
            if(i < n - 1){
                minim = min(minim, (ll)a[i].se);
            }
        }
        ans = max(ans, sum - minim);
    }
    else {
        ll sum = a[n-1].fi;
        int mi = 1e9;
        for(int i=n-2;i>=0;--i){
            sum += a[i].fi;
            mi = min(mi, a[i].se);
        }
        ans = max(ans, sum - mi);
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