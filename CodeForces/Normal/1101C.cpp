#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-9
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void printArray(const int *arr, int n);
void printArray(const vector<int> &arr);

const ll mod = 1e9+7;
const double PI = acos(-1);

int n,i,j,k,t;
pair<pii, int> p[100002];
int ans[100002];

bool isConflict(const pii &a, const pii &b){
    return !(b.se < a.fi || a.se < b.fi);
}

pii merge(const pii &a, const pii &b){
    return {min(a.fi, b.fi), max(a.se, b.se)};
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i=0;i<n;++i){
            scanf("%d %d", &p[i].fi.fi, &p[i].fi.se);
            p[i].se = i;
        }
        sort(p, p+n);
        pii a = {-1, -1}, b = {-1, -1};
        vector<int> ansa, ansb;
        bool bisa = true;
        int cnta=0, cntb=0;
        for(int i=0;i<n;++i){
            if(isConflict(a, p[i].fi) && isConflict(b, p[i].fi)){
                bisa = false;
                break;
            }
            else if(isConflict(a, p[i].fi)){
                a = merge(a, p[i].fi);
                ans[p[i].se] = 1;
                cnta++;
            }
            else if(isConflict(b, p[i].fi)){
                b = merge(b, p[i].fi);
                ans[p[i].se] = 2;
                cntb++;
            }
            else{
                if(cnta == 0){
                    a = merge(a, p[i].fi);
                    ans[p[i].se] = 1;
                    cnta++;
                }
                else{
                    b = merge(b, p[i].fi);
                    ans[p[i].se] = 2;
                    cntb++;
                }
            }
        }
        if(cnta == 0 || cntb == 0) bisa = false;
        if(bisa){
            for(int i=0;i<n;++i){
                printf("%d ", ans[i]);
            }
            puts("");
        }
        else{
            puts("-1");
        }
    }
	return 0;
}

/* Template Function */
void printArray(const int * a, int n){
	for(int i=0;i<n;++i){
		printf("%d ", a[i]);
	}
	puts("");
}

void printArray(const vector<int> &arr){
	for(int x : arr){
		printf("%d ", x);
	}
	puts("");
}