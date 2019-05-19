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
int a[300000], s[300000];
vector<int> pos[300000];

void bf(int n){
    vector<int> v;
    vector<bool> used;
    for(int i=0;i<n;++i){
        v.pb(i);
        v.pb(i);
    }
    do{
        used.assign(n, 0);
        set<int> wew;
        for(int i=0;i<v.size();++i){
            if(used[v[i]]) continue;
            used[v[i]] = true;
            int xors = 0;
            for(int j=i+1;j<v.size();++j){
                if(v[i] == v[j]){
                    wew.insert(xors);
                    break;
                }
                xors ^= v[j];
            }
        }
        if(wew.size() == 1){
            printf("%d:", *wew.begin());
            for(int x : v){
                printf(" %d", x);
            }
            puts("");
        }
        if(v[0] >= n/2) break;
    }while(next_permutation(v.begin(), v.end()));
}

int main(){
	scanf("%d %d", &n, &k);
    // bf(1<<n);
    if(k >= (1<<n) || (n==1 && k>=1)) return puts("-1"), 0;
    int b = 1<<n;
    if(k==0){
        for(int i=0;i<b;++i){
            a[2*i] = a[2*i+1] = i;
        }
    }
    else{
        a[0] = a[b-1] = 0;
        a[b] = a[2*b-1] = k;
        for(int i=1;i<b-1;++i){
            a[i] = a[i+b] = i + (i>=k);
        }
        reverse(a+1, a+b-1);
        for(int i=0;i<2*b;++i){
            s[i+1] = s[i] ^ a[i];
            pos[a[i]].pb(i);
        }
        bool bisa = true;
        for(int i=0;i<b;++i){
            if((s[pos[i][1]+1] ^ s[pos[i][0]]) != k) bisa = false;
        }
        if(!bisa) return puts("-1"), 0;
    }
    for(int i=0;i<2*b;++i)
        printf("%d ", a[i]);
    puts("");
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