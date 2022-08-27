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
int a[2002];
vector<int> v;
int cnt[2002], b[2002];

int main(){
	scanf("%d", &n);
    for(int i=0;i<n;++i){
        scanf("%d", a+i);
        v.pb(a[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i=0;i<n;++i){
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
        cnt[a[i]]++;
    }
    int ans = n;
    bool bisa = true;
    for(int i=0;i<n;++i){
        if(cnt[i] > 1){
            bisa = false;
            break;
        }
    }
    if(bisa) return puts("0"), 0;
    for(int i=0;i<n;++i){
        map<int, int> mep;
        memset(b, 0, sizeof b);
        for(int j=0;j<n;++j){
            if(cnt[a[j]] > 1)
                mep[a[j]] = cnt[a[j]];
        }
        for(int j=i;j<n && mep.size();++j){
            if(mep.count(a[j])){
                mep[a[j]]--;
                if(mep[a[j]] < 2){
                    mep.erase(a[j]);
                    if(mep.size() == 0){
                        ans = min(ans, j-i+1);
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
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