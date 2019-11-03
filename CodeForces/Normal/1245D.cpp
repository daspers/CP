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

struct node{
    int id;
    int pre;

    node(int _id, int _pre): id(_id), pre(_pre){}
    node(int _id): id(_id), pre(-1){}

    bool operator<(const node& ot){
        return id < ot.id;
    }
    bool operator>(const node& ot){
        return id > ot.id;
    }
};

int n,i,j,k,t;
pii p[2002];
int c[2002];
int a[2002];
bool vis[2002];

int dist(const pii &a, const pii &b){
    return abs(a.fi - b.fi) + abs(a.se - b.se);
}

ll conn_cost(int na, int nb){
    return 1LL * dist(p[na], p[nb]) * (a[na] + a[nb]);
}

int main(){
    scanf("%d", &n);
    for(int i=0;i<n;++i){
        scanf("%d %d", &p[i].fi, &p[i].se);
    }
    for(int i=0;i<n;++i){
        scanf("%d", c+i);
    }
    for(int i=0;i<n;++i){
        scanf("%d", a+i);
    }
    priority_queue<pair<ll, pii>> pq;
    for(int i=0;i<n;++i){
        pq.push({-c[i], {-1, i}});
    }
    ll cost = 0;
    vector<int> ans1;
    vector<pii> ans2;
    while(!pq.empty()){
        pair<ll, pii> tmp = pq.top(); pq.pop();
        if(vis[tmp.se.se]) continue;
        vis[tmp.se.se] = true;
        if(tmp.se.fi == -1) ans1.pb(tmp.se.se);
        else ans2.pb(tmp.se);
        cost -= tmp.fi;
        for(int i=0;i<n;++i){
            if(vis[i]) continue;
            pq.push({-conn_cost(tmp.se.se, i), {tmp.se.se, i}});
        }
    }
    printf("%lld\n", cost);
    printf("%d\n", (int)ans1.size());
    for(int x : ans1) printf("%d ", x+1);
    puts("");
    printf("%d\n", (int)ans2.size());
    for(pii x : ans2) printf("%d %d\n", x.fi+1, x.se+1);
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