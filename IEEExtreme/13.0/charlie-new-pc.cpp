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
int s;
vector<int> v[10];
int l[11];
ll sma[11], smi[11];
int ans = 0;
ll curr = 0;
deque<int> st;

void bf(int idx){
    if(idx == n) {
        // debug(ans);
        // for(int x : st){
        //     printf("%d ", x);
        // }
        // puts("");
        ans = max(ans, (int)curr);
        return;
    }
    int ub = upper_bound(v[idx].begin(), v[idx].end(), s - curr - smi[idx+1]) - v[idx].begin() - 1;
    for(int i = ub;i>=0;--i) {
        // debug3(idx, v[idx][i], sma[idx+1]);
        if(curr + v[idx][i] + sma[idx+1] <= ans){
            return;
        }
        // if(curr + v[idx][i] + smi[idx+1] <= s){
            // st.push_back(v[idx][i]);
            curr += v[idx][i];
            bf(idx+1);
            curr -= v[idx][i];
            // st.push_back(v[idx][i]);
        // }
    }
}

int main(){
    scanf("%d", &t);
    while(t--){
        for(int i=0;i<10;++i){
            v[i].clear();
        }
        scanf("%d", &s);
        scanf("%d", &n);
        for(int i=0;i<n;++i){
            scanf("%d", l+i);
        }
        ll sum = 0;
        sma[n] = smi[n] = 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<l[i];++j){
                int x;
                scanf("%d", &x);
                v[i].pb(x);
            }
            sort(v[i].begin(), v[i].end());
            v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
        }
        for(int i=n-1;i>=0;--i){
            sma[i] = sma[i+1] + v[i].back();
            smi[i] = smi[i+1] + v[i].front();
        }
        if(smi[0] > s){
            printf("0");
            continue;
        }
        ans = smi[0];
        bf(0);
        printf("%d\n", ans);
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