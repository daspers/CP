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

int powmod(int base, int exp, int mod){
    int ans = 1;
    for(int val=base%mod;exp;exp>>=1){
        if(exp&1)
            ans = 1LL*ans*val%mod;
        val = 1LL*val*val%mod;
    }
    return ans;
}

int main(){
    int p2 = 787109376;
    int p5 = 212890625;
    scanf("%d", &t);
    while(t--){
        int x, y;
        scanf("%d %d", &x, &y);
        if(x % 10 == 0){
            puts("0");
        }
        else if(__gcd(x, 10) > 1){
            int modu = pow(10, y);
            x %= modu;
            // vector<int> v;
            // set<int> s;
            // ll now  = x;
            // do{
            //     v.pb(now);
            //     s.insert(now);
            //     now = 1LL * now * x % modu;
            // }while(!s.count(now));
            // for(int i=0;i<v.size();++i){
            //     if(v[i] == now) {
            //         cerr<<"cycle length : "<<(int)v.size() - i << " with offset "<< i<<endl;
            //         cerr<<"min element: "<<*min_element(v.begin()+i, v.end())<<endl;
            //     }
            // }
            if(__gcd(x, 10) == 2){
                int cnt = 0;
                int tmp = x % modu;
                do{
                    cnt++;
                    tmp /= 2;
                }while(tmp % 2 == 0);
                int offset = (y-1)/cnt;
                int now = p2%modu;
                int ans = now;
                for(int i=0;i<86399;++i){
                    now = 1LL * now * x % modu;
                    ans = min(ans, now);
                }
                printf("%d\n", ans);
            }
            else {
                int cnt = 0;
                int tmp = x % modu;
                do{
                    cnt++;
                    tmp /= 5;
                }while(tmp % 5 == 0);
                int offset = (y-1)/cnt;
                int now = p5 % modu;
                int ans = now;
                for(int i=0;i<86399;++i){
                    now = 1LL * now * x % modu;
                    ans = min(ans, now);
                }
                printf("%d\n", ans);
            }
        }
        else {
            puts("1");
        }
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