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

struct point{
    int x, y, z, id;
};

ostream& operator<<(ostream& os, const point & a){
    return os<<"("<<a.x<<","<<a.y<<","<<a.z<<")";
}

const ll mod = 1e9+7;
const double PI = acos(-1);

int n,i,j,k,t;
point a[50002];
int le[50002];
int ri[50002];
bool used[50004];

int main(){
    scanf("%d", &n);
    int mix=1e8, miy=1e8, miz=1e8;
    for(int i=1;i<=n;++i){
        scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].z);
        mix = min(mix, a[i].x);
        miy = min(miy, a[i].y);
        miz = min(miz, a[i].z);
    }
    for(int i=1;i<=n;++i){
        a[i].x -= mix;
        a[i].y -= miy;
        a[i].z -= miz;
        a[i].id = i;
        ri[i] = i+1;
        le[i] = i-1;
    }
    ri[0] = 1;
    le[n+1] = n;
    ri[n+1] = n+1;
    le[0] = 0;
    sort(a+1, a+n+1, [](const point& a, const point& b){
        if(a.x == b.x){
            if(a.y == b.y){
                return a.z < b.z;
            }
            return a.y < b.y;
        }
        return a.x < b.x;
    });
    vector<pii> ans;
    int rem = n;
    for(int i=1;i<=n;++i){
        if(used[i]) continue;
        int p = -1;
        int xmi;
        int xma;
        int ymi;
        int yma;
        int zmi;
        int zma;
        for(int j=i+1;j<=n;++j){
            if(used[j]) continue;
            if(p == -1){
                xma = max(a[i].x, a[j].x);
                xmi = min(a[i].x, a[j].x);
                ymi = min(a[i].y, a[j].y);
                yma = max(a[i].y, a[j].y);
                zmi = min(a[i].z, a[j].z);
                zma = max(a[i].z, a[j].z);
                p = j;
            }
            else {
                if(!(a[j].x < xmi || a[j].x > xma || a[j].y < ymi || a[j].y > yma || a[j].z < zmi || a[j].z > zma)){
                    xma = max(a[i].x, a[j].x);
                    xmi = min(a[i].x, a[j].x);
                    ymi = min(a[i].y, a[j].y);
                    yma = max(a[i].y, a[j].y);
                    zmi = min(a[i].z, a[j].z);
                    zma = max(a[i].z, a[j].z);
                    p = j;
                }
            }
        }
        ans.pb({a[i].id, a[p].id});
        used[i] = true;
        used[p] = true;
    }
    // while(rem > 0){
    //     printArray(le, n+2);
    //     printArray(ri, n+2);
    //     for(int i=ri[0];i<=n;i=ri[ri[i]]){
    //         int xmi = min(a[i].x, a[ri[i]].x);
    //         int xma = max(a[i].x, a[ri[i]].x);
    //         int ymi = min(a[i].y, a[ri[i]].y);
    //         int yma = max(a[i].y, a[ri[i]].y);
    //         int zmi = min(a[i].z, a[ri[i]].z);
    //         int zma = max(a[i].z, a[ri[i]].z);
    //         if((le[i] < 1 || a[le[i]].x < xmi || a[le[i]].x > xma || a[le[i]].y < ymi || a[le[i]].y > yma || a[le[i]].z < zmi || a[le[i]].z > zma) && 
    //         (ri[i] > n || a[ri[ri[i]]].x < xmi || a[ri[ri[i]]].x > xma || a[ri[ri[i]]].y < ymi || a[ri[ri[i]]].y > yma || a[ri[ri[i]]].z < zmi || a[ri[ri[i]]].z > zma)){
    //             rem -= 2;
    //             ans.pb({a[i].id, a[ri[i]].id});
    //             debug6(xmi,xma,ymi,yma,zmi,zma);
    //             debug4(a[i].id, a[ri[i]].id, a[i], a[ri[i]]);
    //             // debug2(i, ri[i]);
    //             ri[le[i]] = ri[ri[i]];
    //             le[ri[ri[i]]] = le[le[i]];
    //             break;
    //         }
    //     }
    // }
    for(pii x : ans){
        printf("%d %d\n", x.fi, x.se);
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