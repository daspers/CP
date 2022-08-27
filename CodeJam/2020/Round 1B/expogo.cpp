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
char moves[33];

int get_fullbit(int val){
    int msb = 32 - __builtin_clz(val);
    return (1 << msb) - 1;
}

void fill_bit(int bits, char val){
    for(int i=0;bits;++i){
        if(bits & 1){
            moves[i] = val;
        }
        bits >>= 1;
    }
}

int main(){
    scanf("%d", &t);
    for(int cc=1;cc<=t;++cc){
        printf("Case #%d: ", cc);
        int x, y;
        scanf("%d %d", &x, &y);
        int tot = abs(x) + abs(y);
        memset(moves, 0, sizeof moves);
        if(tot % 2 == 0){
            puts("IMPOSSIBLE");
            continue;
        }
        int ma = get_fullbit(tot);
        int ub = ma, lb = ma - tot;
        int diff = -1;
        for(int i=0;i<=lb;++i){
            // debug4(ub-i, lb-i, (ub-i)&(lb-i), (ub-i)^(lb-i));
            if(((ub-i)&(lb-i)) == 0 && ((ub-i)^(lb-i)) == ma){
                diff = i;
                break;
            }
        }
        if(diff == -1){
            puts("IMPOSSIBLE");
            continue;
        }
        ub -= diff;
        lb -= diff;
        // debug2(ub, lb);
        for(int i=ub;i>0;i=(i-1)&ub){
            int tmp = (i-abs(x));
            if((tmp & lb) == tmp){
                if(x > 0){
                    fill_bit(i, 'E');
                    fill_bit(tmp, 'W');
                }
                else {
                    fill_bit(i, 'W');
                    fill_bit(tmp, 'E');
                }
                if(y > 0){
                    fill_bit(ub - i, 'N');
                    fill_bit(lb - tmp, 'S');
                }
                else {
                    fill_bit(ub - i, 'S');
                    fill_bit(lb - tmp, 'N');
                }
                break;
            }
            tmp = (i - abs(y));
            if((tmp & lb) == tmp){
                if(y > 0){
                    fill_bit(i, 'N');
                    fill_bit(tmp, 'S');
                }
                else {
                    fill_bit(i, 'S');
                    fill_bit(tmp, 'N');
                }
                if(x > 0){
                    fill_bit(ub - i, 'E');
                    fill_bit(lb - tmp, 'W');
                }
                else {
                    fill_bit(ub - i, 'W');
                    fill_bit(lb - tmp, 'E');
                }
                break;
            }
        }
        printf("%s\n", moves);
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