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

template<class T>
struct mapper{
   std::vector<T> m;
   mapper(){}
   mapper(const T *arr, int sz){mapping(arr, sz);}
   mapper(const vector<T> &arr){mapping(arr);}
   void mapping(const T *arr, int sz){
       m.clear();
       for(int i=0;i<sz;++i)
           m.pb(arr[i]);
       sort(m.begin(), m.end());
       m.erase(unique(m.begin(), m.end()), m.end());
   }
   void mapping(const vector<T> &arr){
       m.clear();
       for(const T &x : arr)
           m.pb(x);
       sort(m.begin(), m.end());
       m.erase(unique(m.begin(), m.end()), m.end());
   }
   int get(const T &val){ return lower_bound(m.begin(), m.end(), val) - m.begin();}
   int ub(const T &val){ return upper_bound(m.begin(), m.end(), val) - m.begin() -1;}
   int operator[] (const T &val){ return get(val);}
};

int n,i,j,k,t;
int a[300002];
int ans[300002];
int ri[300002];
mapper<int> mep;
// int dp[200002];

int tree1[400010];

void build1(int l, int r, int pos){
    if(l == r){
        tree1[pos] = 1e9;
        return;
    }
    int mid = (l+r)/2;
    build1(l, mid, 2*pos+1);
    build1(mid+1, r, 2*pos+2);
    tree1[pos] = min(tree1[2*pos+1], tree1[2*pos+2]);
}

int idx, val;
void update1(int l, int r, int pos){
    if(l > idx || r < idx) return;
    if(l == r){
        tree1[pos] = val;
        return;
    }
    int mid = (l+r)/2;
    update1(l, mid, 2*pos+1);
    update1(mid+1, r, 2*pos+2);
    tree1[pos] = min(tree1[2*pos+1], tree1[2*pos+2]);
}

int ql, qr;
int query1(int l, int r, int pos){
    if(l > qr || r < ql) return 1e9;
    if(l >= ql && r <= qr) return tree1[pos];
    int mid = (l+r)/2;
    return min(query1(l, mid, 2*pos+1), query1(mid+1, r, 2*pos+2));
}

int tree2[1200012];

void build2(int l, int r, int pos){
    if(l == r){
        tree2[pos] = ri[l];
        return;
    }
    int mid = (l+r)/2;
    build2(l, mid, 2*pos+1);
    build2(mid+1, r, 2*pos+2);
    tree2[pos] = min(tree2[2*pos+1], tree2[2*pos+2]);
}

int query2(int l, int r, int pos){
    if(l > qr || r < ql) return 1e9;
    if(l >= ql && r <= qr) return tree2[pos];
    int mid = (l+r)/2;
    return min(query2(l, mid, 2*pos+1), query2(mid+1, r, 2*pos+2));
}

int main(){
    scanf("%d", &n);
    int ma = 0, mi = 1e9;
    for(int i=0;i<n;++i){
        scanf("%d", a+i);
        a[i+n] = a[i];
        a[i+2*n] = a[i];
        ma = max(ma, a[i]);
        mi = min(mi, a[i]);
    }
    if((ma+1)/2 <= mi){
        for(int i=0;i<n;++i){
            printf("-1 ");
        }
        puts("");
        return 0;
    }
    mep.mapping(a, n);
    build1(0, n-1, 0);
    ql = 0;
    for(int i=3*n-1;i>=0;--i){
        qr = mep.ub((a[i]-1)/2);
        if(qr < 0) ri[i] = 1e9;
        else ri[i] = query1(0, n-1, 0);
        idx = mep[a[i]];
        val = i;
        qr = 0;
        update1(0, n-1, 0);
    }
    build2(0, 3*n-1, 0);
    for(int i=0;i<n;++i){
        int l=i, r=i+2*n;
        ql = i;
        // debug(i);
        // debug2(l, r);
        while(l<r){
            int mid = (l+r+1)/2;
            qr = mid;
            // debug2(ql, qr);
            // debug2(mid, query2(0, 3*n-1, 0));
            if(query2(0, 3*n-1, 0) <= mid){
                r = mid-1;
            }
            else{
                l = mid;
            }
        }
        // debug2(l, r);
        ans[i] = l - i+1;
        if(ans[i] > 3*n) ans[i] = -1;
    }
    for(int i=0;i<n;++i){
        printf("%d ", ans[i]);
    }
    puts("");
    return 0;
}

/* Template Function */
template<class T>
void printArray(const T * a, int n, ostream& out){
    for(int i=0;i<n;++i){
        out<<i<<":"<<a[i]<<" ";
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