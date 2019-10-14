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
bool isp[10000];
vector<ll> p;
int x;

int main(){
    memset(isp, 1, sizeof isp);
    for(int i=2;i<10000;++i){
        if(!isp[i]) continue;
        p.pb(i);
        for(int j=i*i;j<10000;j+=i){
            isp[j] = false;
        }
    }
    for(int i=1;i<p.size();++i){
        p[i] += p[i-1];
    }
	scanf("%d", &n);
    for(int i=0;i<n;++i){
        scanf("%d", &x);
        printf("%d\n", p[x-1]);
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