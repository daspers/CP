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
int cnt1[1000002];
int cnt2[1000002];

int main(){
    ll k;
    scanf("%d %lld", &n, &k);
    if(1LL*n*(n+1)/2 > k){
        return puts("-1");
    }
    ll sum = 0;
    vector<int> v, w;
    for(int i=1;i<=n;++i){
        v.pb(i);
        cnt2[i]=1;
    }
    int ma = n;
    k -= 1LL*n*(n+1)/2;
    cnt1[n]++;
    for(int i=n-2;i>=0&&k>0;--i){
        while(ma > 0 && cnt2[ma] == 0) --ma;
        while(k < ma - v[i] && ma > v[i]) --ma;
        k -= ma - v[i];
        cnt2[ma]--;
        cnt2[v[i]]++;
        cnt1[ma]++;
        v[i] = ma;
    }
    sum = 0;
    for(int x : v){
        sum += x;
    }
    for(int i=1;i<=n;++i){
        for(int j=0;j<cnt2[i];++j){
            w.pb(i);
        }
    }
    sort(v.begin(), v.end(), [](int a, int b){
        if(cnt1[a] == cnt1[b]) return a < b;
        return cnt1[a] < cnt1[b];
    });
    sort(w.begin(), w.end(), [](int a, int b){
        if(cnt2[a] == cnt2[b]) return a < b;
        return cnt2[a] < cnt2[b];
    });
    for(int i=n-1;i>=0;--i){
        if(v[i] != w[i] && cnt1[v[i]]>1 && cnt2[w[i]]>1){
            cnt1[v[i]]--;
            cnt1[w[i]]++;
            cnt2[w[i]]--;
            cnt2[v[i]]++;
            swap(v[i], w[i]);
        }
    }
    printf("%lld\n", sum);
    for(int i=0;i<v.size();++i){
        printf("%d ", v[i]);
    }
    puts("");
    for(int i=0;i<w.size();++i){
        printf("%d ", w[i]);
    }
    puts("");
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